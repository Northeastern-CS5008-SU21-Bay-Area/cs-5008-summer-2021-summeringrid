//Xiaoying Liu
//liu.xiaoying@northeastern.edu
/*
Selection Sort
1. traverse whole array, find the lowest one;
2. swap the lowest one to the position of index0
3. move the sorted array|unsorted array boundary +1
4. repeat the above steps until unsorted section is empty
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 50
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

  printf("Source array:\n");
  // printf("LIMIT/5=%f\n", (double)(LIMIT/5));
  for (i=0; i < ((LIMIT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < LIMIT) {
	     printf("%.2d ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  //selection sort
  for (i=0; i<LIMIT; i++) {

    // 1/2*******INSERT YOUR CODE HERE
    dest[i] = source[i];
  }

  for (i=0; i<LIMIT-1; i++) {
    smallest = dest[i];
    for (j=i+1; j<LIMIT; j++){
      if(dest[j]<smallest){
        smallest=dest[j];
        dest[j]=dest[i];
        dest[i]=smallest;
      }
    }
  }
  
  //print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i=0; i < ((LIMIT/10)+1); i++) {
    // 2/2********INSERT YOUR CODE HERE
    for (j=0;j<10;j++){
      if(i*10+j<LIMIT){
         printf("%.2d ", dest[i*10+j]);
      }
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
