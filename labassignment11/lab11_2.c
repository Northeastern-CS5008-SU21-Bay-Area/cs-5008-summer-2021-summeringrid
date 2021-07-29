// name: Xiaoying Liu
// email: liu.xiaoying@northeastern.edu
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
    int left = n;
    int right = (n+1)%5;
    //1. Print the philosopher (number)is thinking
    printf("Philosopher %d is thinking.\n",n);
    //2. Put the mutex lock for the left chopstick
    pthread_mutex_lock(&chopstick[left]);
    //3. Put the mutex lock for the right chopstick
    pthread_mutex_lock(&chopstick[right]);
    //4. Print the philosopher (number) is eating with the chopstick (numbers).
    printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d]\n",n,left,right);
    //5. Sleep for sometime. Use sleep(1) statement.
    sleep(1);
    //6. Unlock the mutex lock for the left chopstick
    pthread_mutex_unlock(&chopstick[left]);
    //7. Unlock the mutex lock for right chopstick
    pthread_mutex_unlock(&chopstick[right]);
    //8. Print the philosopher (number) is finished eating
    printf("Philosopher %d finished eating.\n",n);

    return NULL;

}


/*------------ Main Program---------*/
int main()
{
    pthread_t threads[5];
    int i,val[5];
    
//initializing the mutex
    for(i=0;i<5;i++)
    {
        pthread_mutex_init(&chopstick[i],NULL);
    }
    
//create and run the thread
    for(i=0;i<5;i++)
    {
        val[i]=i;
        pthread_create(&threads[i], NULL,(void *)philosopher,&val[i]);
    }
    
//wait until all the threads are done
    for(i=0; i<5;i++)
    {
        pthread_join(threads[i], NULL);
    }
    
// Destroying the mutex
    for(i=0;i<5;i++)
    {
        pthread_mutex_destroy(&chopstick[i]);
    }
    
    return 0;
}
