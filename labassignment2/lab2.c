//enter your name here
// enter your email here

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 8

int queue[N];
int front = -1;
int rear = -1;
int elementcount = 0;

int peek() {
   return queue[front]; // To see the data at the front of the queue//
}
bool isempty()
{
    return elementcount==0; //checking if the queue is empty
}

bool isfull()
{
    
    return elementcount==N;// checking if the queue is full
}


int enqueue(int data)
{
//insert your code here
}


void dequeue()
{
    
    //insert your code here
    
}
void display()
{
    
    
    //insert your code here
}

int main()
    {
   /* insert 8 items */
enqueue(11);
enqueue(22);
enqueue(33);
enqueue(44);
enqueue(66);
enqueue(77);
enqueue(88);
enqueue(99);
display();
printf("\n");
dequeue();
dequeue();
dequeue();
dequeue();
display();
    
printf("\n Element at front: %d\n",peek());
printf(" \nTotal number of elements in the queue are %d\n", elementcount);

        
return 0;
    }

