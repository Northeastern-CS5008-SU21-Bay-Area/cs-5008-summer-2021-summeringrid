//Enter your name here
//Enter your email here
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t chopstick[5];//lock variable

// Thread to be executed
void *philosopher(void *x)
{
 //Treat variable x as a pointer to an int and then extract the value into n
    int* a=(int*)x;
    int n=*a;
    
        /*-----Insert your code here----*/
    
    
}


/*------------ Main Program---------*/
int main()
{
    pthread_t threads[5];
    int i,val[5];
    
//initializing the mutex
    
//create and run the thread
    
//wait until all the threads are done
    
// Destroying the mutex
    
    return 0;
}
