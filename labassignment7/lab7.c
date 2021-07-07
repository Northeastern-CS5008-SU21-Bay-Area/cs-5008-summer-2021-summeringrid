//Xiaoying Liu
//liu.xiaoying@northeastern.edu
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// suspends the program: ctrl + Z (input 4 in this program)
typedef struct node
{
    char name[20];
    int age;
    char address[100];
    int reg;
    int priority;
    struct node *next;
}node_t;

/* Inserting patients in the queue based on priority*/
node_t *insert(struct node *front)
{
    
    node_t *p,*temp;
    char name[20],address[100];
    temp=(node_t*)malloc(sizeof(struct node));
    printf("Enter patient Name:");
    scanf(" %s",temp-> name);       // String is an array of char, so string itself is a pointer
    printf("Enter the patient's age:");
    scanf("%d",&(temp->age));
    printf("Enter the address:");
    scanf(" %s",temp->address);
    printf("Enter the reg no:");
    scanf("%d",&(temp->reg));
    printf("Enter the priority:");
    scanf("%d",&(temp->priority));
    int pri=temp->priority;
    
//**********2-1 insert your code here
    // if(front=null or priority > priority of the node already present) then insert the node at front
    // inserting the node by traversing through the list and finding the correct position [use a while loop]
    // if next != null && P.next's priority >= this temp.priority then ...

    //1. if(front=null) OR pri > priority of the node already present -> insert the node at front
    if (front==NULL || pri >= front->priority)
    {
        node_t *curr;
        curr = front;
        front = temp;
        temp->next = curr;
    } 
    //2. finding the correct position to insert new patient 
    else
    {
        node_t *curr2;
        p = front;
        while (p->next != NULL && p->next->priority >= pri)
        {
            p = p->next;
        }
        curr2 = p->next;
        p->next = temp;
        temp->next = curr2;
    }
    // free(temp);      // I shouldn't free temp, if I free it, it will gone! It's a new added (and should exsiting) node!)
    // Q: do I need to malloc for p and other temporary variables? Why?
    // A: malloc for temp because it is the place where to create a node, but for other temporary pointers, no need to malloc for a pointer
    return front;
    
}

/* Delete the node which is present at the front*/
node_t *delete(struct node *front)
{
    //**********2-2 insert your code here
    // delete the patient who is served first
    // straight forward, follow the instruction step by step

    front = front->next;
    return front;
    
}


/* To display the patients records */
void display(node_t *front)
{
    node_t *temp=front;
    if(front==NULL)
    printf("\nTHERE IS NO PATIENT");
    else
    {
        printf("\nPriority wise appointments are:\n");
        while(temp!=NULL)
        {
        printf("The name of patient is:%s\n",temp->name);
        printf("The age of patient is:%d\n",temp->age);
        printf("The address of patient is : %s\n",temp->address);
        printf("---------------------------------------------------\n");
        temp=temp->next;
        }
    }
    return;
}

/*-----------------Main program---------------------------*/
int main()
{
    node_t *front=NULL;
    int option;
    do
{
    
    printf("\t\t\t Hospital emergency room system\n");
    printf("\t\t\t1.ADD A PATIENT\n");
    printf("\t\t\t2.DELETE A RECORD\n");
    printf("\t\t\t3.DISPLAY ALL PATIENTS RECORDS\n");
    printf("\t\t\tEnter your choice:");
    scanf("%d",&option);
    switch(option)
        {
        /*Select 1 to insert elements in the priority queue*/
    case 1:
        front= insert(front);
        break;
        /* Select 2 to delete the elements at the front of priority queue*/
    case 2:
        front= delete(front);
        break;
        /* Select 3 To display the elements present in the priority queue*/
    case 3:
        display(front);
        break;
        /* Select 4 to exit*/
    case 4:
        exit(0);
        break;
        }
    }
    while(option!=4);
}





