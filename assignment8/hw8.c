// name: Xiaoying Liu
// email: liu.xiaoying@northeastern.edu

// format of document is a bunch of data lines beginning with an integer (rank which we ignore)
// then a ',' followed by a double-quoted string (city name)
// then a ',' followed by a double-quoted string (population) - ignore commas and covert to int; or (X) - convert to 0
// then a lot of entries that are ignored


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200
#define HASHSIZE 400

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

// check if a character c is a digit
bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// append character c to string s
void appendChar(char* s, char c) {
  char charToStr[2];           // convert char to string
    charToStr[0] = c;
    charToStr[1] = '\0';          // put NUL to terminate string of one character
    strcat(s, charToStr);
}


// ******** key value pairs *******
typedef struct kv {
  char key [MAXSTRING];
  int value;
  struct kv* next;
} keyvalue_t;

// create new keyvalue pair with key s and value i
keyvalue_t* newKeyValue(char* s, int i) {
  keyvalue_t* t = (keyvalue_t*)malloc(sizeof(keyvalue_t));
  if (t != NULL) {
    strcpy(t->key, s);
    t->value = i;
    t->next = NULL;
  }

  return t;
}

//free a used keyvalue pair
void freeKeyValue(keyvalue_t* kvp) {
  if (kvp != NULL) {
    free(kvp);
  }
}

// ******** hash table manipulation  *******
// hash 1 is just the length of the string
int hash1(char* s) {
  return (strlen(s) % HASHSIZE);
}

// hash 2 is the sum of the char codes of string
int hash2(char* s) {
  int sumOfS = 0;
  int i;
  for (i=0; i<strlen(s); i++){
    sumOfS += (int)s[i];
  }

  return (sumOfS % HASHSIZE);
}

// hash 3 is the prioduct of the first two char codes of string
int hash3(char* s) {
  long productOfS = 1;
  int i;
  for (i=0; i<2; i++){
    productOfS *= (int)s[i];
  }

  return ((int)(productOfS % HASHSIZE));
}




// add (key k, value v) to hashtable t at location loc
// note that a t is an array of keyvalue pointers
// return true if successful, false if not
bool addToHashTable(keyvalue_t* t[], int loc, char* k, int v) {
  bool result = true;
  if ((0<=loc) && (loc<HASHSIZE)) {
    keyvalue_t* kv = newKeyValue(k, v); // create new kv pair

    // insert kv in the front of linked list at location loc
    kv->next = t[loc];
    t[loc] = kv;
  } else {
    result = false;
  }

  return result;
}

// print the linked list pointed to by p
void printHashList(keyvalue_t* p){
  while (p != NULL) {
    printf("key/value: [%s] / [%d]\n",p->key,p->value);
    p = p->next;
  }

  return;
}

// print the hash table t
void printHashTable(keyvalue_t* t[]) {
  int i;
  printf("====================\n");
  for (i=0; i<HASHSIZE; i++) {
    printf("TABLE[%d]:\n",i);
    printHashList(t[i]);
    printf("\n");
  }
  printf("====================\n");
  
  return;
}

// free the hash list in table ht location i
void freeHashList(keyvalue_t* ht[], int i){
  keyvalue_t* t;
  while (ht[i] != NULL){
    t = ht[i];
    ht[i] = ht[i]->next;
    freeKeyValue(t);
  }

  return;
}

// free up kv pairs in hash table t
void freeHashTable(keyvalue_t* t[]) {
  int i;
  for (i=0; i<HASHSIZE; i++) {
    freeHashList(t,i);
  }

  return;
}

// return true if t is empty
bool isHashTableEmpty(keyvalue_t* t[]) {
  bool result = true;
  int i;

  for (i=0; i<HASHSIZE; i++) {
    result = result && (t[i] == NULL);
  }

  return result;
}


int main () {

  char inputLine[MAXSTRING];   // temporary string to hold input line
  char cityStr[MAXSTRING];     // city name
  int  lineNum;                // line number (city rank)
  int  popInt;                 // population
  int  state;                  // FSM state
  int  nextChar;               // index of next character in input string
  char temp[MAXSTRING];        // temp string to build up extracted strings from input characters
  int  i;                      // loop variable
  
  // declare hash table as an array of pointers to keyvalue pairs
  keyvalue_t* hashtable1[HASHSIZE];
  keyvalue_t* hashtable2[HASHSIZE];
  keyvalue_t* hashtable3[HASHSIZE];

  // initialize the hash table entries to NULL
  for (i=0; i<HASHSIZE; i++) {
    hashtable1[i] = NULL;
    hashtable2[i] = NULL;
    hashtable3[i] = NULL;
  }

  FILE* fp;
  fp = fopen("pop.csv","r");

  if (fp != NULL) {
    fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

    // ***** BEGIN FINTITE STATE MACHINE *****
    
    // STARTSTATE: digit -> S1
    // S1: digit -> S1; , -> S2
    // S2: " -> S3
    // S3: !" -> S3; " -> S4
    // S4: , -> S5
    // S5: " -> S6; ( -> ACCEPTSTATE
    // S6: digit -> S6; , -> S6; " -> ACCEPTSTATE; 
    // ACCEPTSTATE: done!
    // else go to ERRORSTATE
    //
    while (feof(fp) == 0){

      nextChar = 0;
      state = STARTSTATE; 
      strcpy(temp,"");

      if (nextChar >= strlen(inputLine)){
	// if no input string then go to ERRORSTATE
	state = ERRORSTATE;
      } 

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
	switch (state) {
	  case STARTSTATE:
	    // look a digit to confirm a valid line
	    if (isDigit(inputLine[nextChar])) {
	      state = S1;
	      appendChar(temp, inputLine[nextChar]);
	    } else {
	      state = ERRORSTATE;
	    }  
	    break;
	    
	  case S1:
	    // accept digits to build up line number (city rank), terminated by comma
	    if (isDigit(inputLine[nextChar])) {
	      state = S1;
	      appendChar(temp, inputLine[nextChar]);
	    } else if (inputLine[nextChar] == ',') {
	      state = S2;
	      // line number is complete - convert it to an int and store in destination
	      sscanf(temp,"%d",&lineNum);
	      strcpy(temp, "");
	    } else {
	      state = ERRORSTATE;
	    } 
	    break;
	    
	  case S2:
	    // expecting a double quote
	    if (inputLine[nextChar] == '\"') {
	      state = S3;
	    } else {
	      state = ERRORSTATE;
	    }
	    break;
	    
	  case S3:
	    // accept anything until you find a double quote
	    // for city name
	    if (inputLine[nextChar] == '\"') {
	      state = S4;
	      // city name is complete - copy it to destination
	      strcpy(cityStr, temp);
	      strcpy(temp, "");
	    } else {
	      state = S3;
	      appendChar(temp,inputLine[nextChar]);
	    }
	    break;
	    
	  case S4:
	    // looking for a comma
	    if (inputLine[nextChar] == ',') {
	      state = S5;
	    } else {
	      state = ERRORSTATE;
	    }
	    break;
	    
	  case S5:
	    // expecting a double quote
	    if (inputLine[nextChar] == '\"') {
	      state = S6;
	    } else if (inputLine[nextChar] == '(') {
	      state = ACCEPTSTATE;
	      // population number is missing - (x) - use 0 instead
	      popInt = 0;
	      strcpy(temp,"");               // temp = ""
	    } else {
	      state = ERRORSTATE;
	    }
	    break;
	    
	  case S6:
	    // looking for digits or commas - terminated by double quote
	    // commas are skipped, digits added to temp string
	    if (isDigit(inputLine[nextChar])) {
	      state = S6;
	      appendChar(temp, inputLine[nextChar]);
	    } else if (inputLine[nextChar] == ',') {
	      state = S6;
	    } else if (inputLine[nextChar] == '\"') {
	      state = ACCEPTSTATE;
	      // population number is complete - convert it to an int and store in destination
	      sscanf(temp,"%d",&popInt);
	      strcpy(temp,"");
	    } else {
	      state = ERRORSTATE;
	    }
	    break;
	    
	  case ACCEPTSTATE:
	    // nothing to do - we are done!
	    break;
	    
	  default:
	    state = ERRORSTATE;
	    break;
	} // end switch

	// advance input
	nextChar++;
	
      }	// end while state machine loop

      // ***** END FINITE STATE MACHINE *****
	  

      // process the line - put it in each hash table
      addToHashTable(hashtable1, hash1(cityStr), cityStr, popInt);
      addToHashTable(hashtable2, hash2(cityStr), cityStr, popInt);
      addToHashTable(hashtable3, hash3(cityStr), cityStr, popInt);

      // get next line
      fgets(inputLine, MAXSTRING, fp);
      
    } // end while file input loop
    

    fclose(fp);
  
  } else {
    printf("File not found!\n");
  }

  printf("\n\n***** HASH TABLE 1 *****\n\n");
  printHashTable(hashtable1);
  printf("\n\n***** HASH TABLE 2 *****\n\n");
  printHashTable(hashtable2);
  printf("\n\n***** HASH TABLE 3 *****\n\n");
  printHashTable(hashtable3);

  freeHashTable(hashtable1);
  freeHashTable(hashtable2);
  freeHashTable(hashtable3);

  if (!isHashTableEmpty(hashtable1)) {
    printf("Hash Table One is NOT empty\n");
  }
  if (!isHashTableEmpty(hashtable2)) {
    printf("Hash Table Two is NOT empty\n");
  }
  if (!isHashTableEmpty(hashtable3)) {
    printf("Hash Table Three is NOT empty\n");
  }

  return 0;
}
