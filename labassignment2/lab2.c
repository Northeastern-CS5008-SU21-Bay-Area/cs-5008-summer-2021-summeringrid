// Xiaoying Liu
// liu.xiaoying@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 8

// 1,2,3,4,5,6,7,8

int queue[N];
int front = -1;				
int rear = -1;
int elementcount = 0;

int peek()
{
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
	front = 0;
	if (!isfull())
	{
	rear++;
	queue[rear] = data;
	elementcount++;
	printf("Enqueued data is: %d\n", queue[rear]);
	}else
	{
		printf("The queue is full.\n");
	}

	return queue[front];

}

void dequeue()
{
	if (!isempty())
	{
		printf("Dequeued data is %d\n", queue[front]);
		front++;
		elementcount--;
	
	}else
	{
		printf("The queue is empty.\n");
	}

}

void display()
{ 
    printf("Queue is: ");
    for (int i = front; i < front + elementcount; i++)
    {
    	printf("%d ", queue[i]);
    }
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
// enqueue(00);		// test isfull()
display();
// printf("\nElement at front: %d\n",peek());
// printf("Total number of elements in the queue are %d\n", elementcount);
printf("\n");
dequeue();
dequeue();
dequeue();
dequeue();
display();

    
printf("\nElement at front: %d\n",peek());
printf("Total number of elements in the queue are %d\n", elementcount);

        
return 0;
    }
