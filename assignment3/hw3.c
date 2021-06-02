// name: Xiaoying Liu
// email: liu.xiaoying@northeastern.edu

#include <stdio.h>   // stardard input/output library
#include <stdbool.h> // standard boolean library: bool, true, false
#include <stdlib.h>  // library that contains malloc, rand, and srand
#include <time.h>    // time functions
                     // https://www.tutorialspoint.com/c_standard_library/

#define MAXMAGNITUDE 100   // the biggest number to be inserted in the queue
#define HOWMANY 10           // how many numbers to be inserted in the queue


/*
 *   queue
 *   +--------+--------+
 *   | tail_p | head_p +----------------------------------------+
 *   +--+-----*--------+                                        |
 *      |                                                       |
 *      V                                                       V
 *   +--------+------+---------+  +--------+------+---------+  +--------+------+---------+  
 *   | left_p | data | right_p +->| left_p | data | right_p +->| left_p | data | right_p +->NULL
 *   |        |      |         |<-+        |      |         |<-+        |      |         |
 *   +--+-----+------+---------+  +--------+------+---------+  +--------+------+---------+  
 *      |       node                         node                         node
 *      V
 *      NULL
 */



//---------------------------- NODE ---------------------------- 
// doubly linked list node
typedef struct nd {
  int data;
  struct nd* left_p;
  struct nd* right_p;
} node_t;

// create new node with value d and NULL left & right pointers
node_t* newNode (int d) {
  node_t* n_p = NULL;                     // temp pointer to hold new node
  n_p = (node_t*)malloc(sizeof(node_t));  // create new node
  if (n_p != NULL) {
    n_p->data = d;                        // put data in node
    n_p->left_p = NULL;
    n_p->right_p = NULL;
  }
  return n_p;
};

// free the node pointed to by n_p
// fragile assumption: this function does not free up nodes pointed to by left/right pointers
void freeNode (node_t* n_p) {
  if (n_p != NULL) {
    free(n_p);
  }
  return;
};



//---------------------------- QUEUE  ---------------------------- 
// a queue - combining a head and a tail pointer
typedef struct q {
  node_t* head_p;
  node_t* tail_p;
} queue_t;

// create new empty queue (head and tail are set to NULL)
queue_t* newQueue() {
  queue_t* q_p;   // temp pointer to hold newly created queue

  // 1/6***** INSERT YOUR CODE HERE *****
  //【 Never forget to allocate memory when create new type】
  q_p = (queue_t*)malloc(sizeof(queue_t));

  // NOTE: I shouldn't let my pointer point to a NULL, I need to make the value of the pointer points to equal to NULL
  q_p->head_p = NULL;
  q_p->tail_p = NULL;
  
  return q_p;
};

// is the queue empty?
bool isEmpty(queue_t* q_p) {
  bool b = true;   // temporary bool to hold return value - initalize to default value

  // 2/6***** INSERT YOUR CODE HERE *****
  if (q_p->head_p != NULL) {
      b = false;
  }
  // NOTE: I shouldn't check the tail_p, once the head_p points to NULL, then it is an emptyQ
  // tail_p is 'technically' always NULL
  
  return b;
};

// function to add a new node with data d to tail of the queue
void enqueue(queue_t* q_p, int d) {
  node_t* n_p = NULL; // temp node pointer
  
  if (q_p != NULL) {        // QUESTION: to see whether if I created a new Queue, right? Can I skip this step?

    if (isEmpty(q_p)) {
      // queue is empty so insertion is easy

      // 3/6***** INSERT YOUR CODE HERE *****
      // my basic idea:
      //(1). create a new node (↑already created n_p) (QUESTION: why I need to set a node pointer n_p ?)
      //(2). set a new node's value as d ↓
      //【3-4】since my queue is empty right now, I need to set the HEAD/TAIL both points to this newNode
      //QUESTION: I thought it should be that left_p points to the Q's HEAD, and right_p points to NULL, do I need to
      // separately set my head/tail and the left/right and why? --- No, not here because it is an empty Q.
      
      node_t* curNode = newNode(d);
      q_p->head_p = curNode;
      q_p->tail_p = curNode;


    } else {
      // queue is not empty

      // 4/6***** INSERT YOUR CODE HERE *****
      // just create a new node and make its value as d
      // set its left_p linked with the right_p of the queue, its right_p points to the value NULL
      // Question ↑ it should be node_t = q_p OR q_p = node_t?

      node_t* curNode = newNode(d);
      // q_p->head_p->left_p = curNode;
      q_p->tail_p->right_p = curNode;     // appending curNode to the tail of p_q
      curNode->left_p = q_p->tail_p;
      q_p->tail_p = curNode;              // now tail will be pointing to the last node


    }    
  }
  
  return;
};

// function to take the node off the head of the queue and return its value
int dequeue(queue_t* q_p) {
  int t = -9999;      // temp int to hold return val with arbitrary error value of -9999
  node_t* n_p = NULL; // temp node poitner
  
  if (q_p != NULL) {
    n_p = q_p->head_p;  // get a pointer to the head of the queue

    if (n_p != NULL) {
	t = n_p->data;      // get the value of data in the head of the queue

	if (q_p->head_p  == q_p->tail_p) {      
      // only one node in the queue, clear queue head and tail 

      // 5/6***** INSERT YOUR CODE HERE *****
        q_p->head_p = NULL;
        q_p->tail_p = NULL;
	} else {
          // mulitple nodes in queue, clean up head pointer and new head of queue

	  // 6/6***** INSERT YOUR CODE HERE *****
        q_p->head_p = n_p->right_p;
        q_p->head_p->left_p = NULL;
	}
	
	freeNode(n_p);  // free up the node that was dequeued
    }
  }
    
  return t;
};


// if queue is not empty, then clean it out -- then free the queue struct
void freeQueue(queue_t* q_p) {
  if (q_p != NULL) {
    // make sure the queue is empty
    while (!isEmpty(q_p)) {
      dequeue(q_p);
    }

    // free up the queue itself
    free(q_p);
  }
  return;
};


// create a random integer between 1 and n
int getRandom(int n) {
  return ((rand() % n) + 1);
}


int main () {
  
  int i;  // loop variable
  int t;  // temporary integer
  
  // create two queues
  queue_t* q1_p = newQueue();
  queue_t* q2_p = newQueue();
  

  // get random number seed
  srand((unsigned)time(NULL));
  
  for (i=0; i<HOWMANY; i++)  {
    t = getRandom(MAXMAGNITUDE);
    printf("enqueue[1] %d\n", t);
    enqueue(q1_p, t);

    t = getRandom(MAXMAGNITUDE);
    printf("enqueue[2] %d\n", t);
    enqueue(q2_p, t);    
  }

  printf("\n");

  printf("dequeue[1]: ");
  while (!isEmpty(q1_p)) {
    printf("%d ", dequeue(q1_p));
  }

  printf("\n");
  
  printf("dequeue[2]: ");
  while (!isEmpty(q2_p)) {
    printf("%d ", dequeue(q2_p));
  }

  printf("\n");

  freeQueue(q1_p);
  freeQueue(q2_p);

  return 0;
}
