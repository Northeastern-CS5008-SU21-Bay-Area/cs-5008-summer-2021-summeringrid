// name: <your name here>
// email: <your email here>

// be prepared 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 20
#define RAND_RANGE 100

int main(){

  int source[LIMIT]; // array to hold input data values
  int dest[LIMIT];   // array to hold sorted data values
                     // use dest only if you are using two arrays
  bool valid[LIMIT]; // array that indicates which input values are valid

  int i;             // loop variable
  int j;             // loop variable
  int smallest;      // current smallest element

  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize valid array - at begining the full array is valid
  for (i=0; i<LIMIT; i++) {
    valid[i] = true;
  }

  //initialize source array with random numbers from 0..RAND_RANGE
  for (i=0; i<LIMIT; i++) {
    source[i] = rand() % RAND_RANGE;
  }

  //print out source array in rows of 5 elements  -> there is 5 columns, LIMIT/5 rows
  printf("Source array:\n");
  for (i=0; i < ((LIMIT/5)+1); i++) {   // row(0,1,2,3)    but i<4+1   //[Question] why +1? 发现不能整除的时候，e.g.6column，就需要+1了！why?
    for (j=0; j<5; j++) {               // column*5(0,1,2,3,4)
      if (i*5+j < LIMIT) {
	printf("%.2d ",source[i*5+j]);                                    //[Question] can't understand this part: i*20+j
      }
    }
    printf("\n");
  }
  printf("\n");

  //selection sort
  for (i=0; i<LIMIT; i++) {

    // INSERT YOUR CODE HERE
    // compare the array[i] with array[i+1] then sort these two items?
    // my option: Bubble Sort/ Selection Sort/ Insertion Sort
    
  }
  
  //print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i=0; i < ((LIMIT/10)+1); i++) {

    // INSERT YOUR CODE HERE
    
  }
  printf("\n");
  
  return 0;
}
