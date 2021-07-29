// name: Xiaoying Liu
// email: liu.xiaoying@northeastern.edu
// Compile with:
//
// gcc -lpthread hw12.c -o hw12
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 100

// shared variable
int counter = 0;

// thread to be executed - unspecified variable arguments
void* thread1 (void* vargp) {
  // add 1 to counter
  counter = counter +1;
  return NULL;
}

void* thread2 (void* vargp) {
  // add 5 to counter
  // *** 1/4 YOUR CODE GOES HERE ***
  counter = counter +5;
  return NULL;
}

void* thread3 (void* vargp) {
  // subtract 2 from counter
  // *** 2YOUR CODE GOES HERE ***
  counter = counter -2;
  return NULL;
}

void* thread4 (void* vargp) {
  // subtract 10 from counter
  // *** 3/4 YOUR CODE GOES HERE ***
  counter = counter -10;
  return NULL;
}

int main() {
  // array to keep Pthread IDs of created threads
  pthread_t tid[NTHREADS*4];
  int i;

  printf("Counter starts at %d\n", counter);
  
  // create and run the thread
  for (i=0; i < NTHREADS; ++i){
    pthread_create(&(tid[i]), NULL, thread1, NULL);
    // *** 4/4 YOUR CODE GOES HERE ***
    pthread_create(&(tid[2*i]), NULL, thread2, NULL);
    pthread_create(&(tid[3*i]), NULL, thread3, NULL);
    pthread_create(&(tid[4*i]), NULL, thread4, NULL);
  }

  //wait until all threads are done
  for (i=0; i < NTHREADS*4; ++i){
    pthread_join(tid[i], NULL);
  }

  printf("Counter ends at %d\n", counter);

  return 0;
}


