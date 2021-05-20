// name: Xiaying Liu
// email: liu.xiaoying@northeastern.edu

#include <stdio.h>   // stardard input/output library
#include <stdbool.h> // standard boolean library: bool, true, false

#define MAXSIZE 100

int s[MAXSIZE];     // stack
int t = -1;         // when top value = -1, the stack is empty

bool isEmpty (int* s, int t) {
  // returns true if t = -1
    // ?can I write: if (t < 0)
    if(t == -1){
        return true;
    }else{
        return false;
    }
}
// given code: bool isFull (int* s, int t) {
bool isFull (int* s, int t) {
  // returns true if no more room in the stack
    if(t >= MAXSIZE){
        return true;
    }else{
        return false;
    }
}
// given code: void push(int v, int* s, int* tp) {
void push(int v, int* s, int* tp) {
  // put v onto the top of the stack s unless it is already full
    if (! isFull(s, *tp)){
//        tp++;
//        *tp = *(tp+1);
        (*tp)++;
        s[*tp] = v;
    }else{
        printf("You are attempting to push %d onto a full stack.\n", v);
    }
    return;
}

int pop (int* s, int* tp) {
  // return the top entry in the stack unless stack is empty
  // update s and *tp -- requires top to be passed by reference!
    // todo 2 why I need to give topvalue an initial value?
    int topvalue = 0;
    if (! isEmpty(s,  *tp)){
        topvalue = s[*tp];
//        tp--;
//        *tp = *(tp-1);
        (*tp)--;
    }else{
        printf("You are attempting to pop from an empty stack.\n");
    }
    return topvalue;
}

int main () {

  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty
  
  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  return 0;
}

