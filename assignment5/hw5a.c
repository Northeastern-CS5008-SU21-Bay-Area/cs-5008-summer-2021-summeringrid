//Xiaoying Liu
//liu.xiaoying@northeastern.edu

/*
 Requriement:
 Merge Sort and test on array of 200 random characters.
 • Hint: you might first try adapting last week’s homework from int to
 char and then change the sort routine
 • Hint: C integer division always returns an int, not a fraction
 
 • NOTE for part a:
 the capital letters are sorted separately from the small letters
 
 
 (expected result sample: slides p184)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95  // 95 printing characters x20-x7E

// return random character
char randChar() {
  // 0 -> x20 -> ' '
  // 1 -> x21 -> '!'
  // ,,,
  // 94 -> x7E -> '~'
  // see https://ascii.cl
  return ((char)((rand() % RAND_RANGE) + 0x20));
}

// return location mid way between left and right
int midPoint(int left, int right){
  // note integer division always returns an integer
  return( left + (right-left)/2 );
}

// min of two integers
int findMin(int a, int b){
  if (a<=b) {return a;} else {return b;}
}

// merge two sorted sub arrays
void mergeIt(
	   char* data,
	   int leftStart,
	   int leftStop,
	   int rightStart,
	   int rightStop) {

  // ******** 1/1 ADD YOUR CODE HERE
    char newArr[rightStop - leftStart + 1];
    int leftIndex = leftStart;
    int rightIndex = rightStart;
    int index = 0;
    
    while(leftIndex <= leftStop && rightIndex <= rightStop) {
        if (data[leftIndex] < data[rightIndex]) {
            newArr[index++] = data[leftIndex++];
        }else {
            newArr[index++] = data[rightIndex++];
        }
    }
    
    while(leftIndex <= leftStop) {
        newArr[index++] = data[leftIndex++];
    }
    
    while(rightIndex <= rightStop) {
        newArr[index++] = data[rightIndex++];
    }
    
    int i = 0;
    int j = leftStart;
    while (i < rightStop - leftStart + 1){
        data[j] = newArr[i];
        i++;
        j++;
    }
  return;
    // attempt2: return newArr
}

// break data array up into halves until down to single elements
// then merge them
void msort(char* data, int left, int right) {

  if (left >= right) {
    // base case of 1 element
    return;
  } else {
    // sort left half
    msort(data, left, midPoint(left,right));

    // sort right half
    msort(data, midPoint(left,right)+1, right);

    // merge left and right halves
    mergeIt(
	    data,
	    left, midPoint(left,right),
	    midPoint(left,right)+1, right
	    );
  }
  return;
}



int main(){

  char source[LIMIT]; // array to hold input data values

  int i;             // loop variable
  int j;             // loop variable
  int smallest;      // current smallest element

  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize source array with random character
  for (i=0; i<LIMIT; i++) {
    source[i] = randChar();
  }

  //print out source array in rows of 20 elments
  printf("Source array:\n");
  for (i=0; i < ((LIMIT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < LIMIT) {
	printf("%c ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // do the sorthing
  msort(source, 0, LIMIT-1);

  
  //print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i=0; i < ((LIMIT/10)+1); i++) {
    for (j=0; j<10; j++) {
      if (i*10+j < LIMIT) {
	printf("%c ",source[i*10+j]);
      }
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
