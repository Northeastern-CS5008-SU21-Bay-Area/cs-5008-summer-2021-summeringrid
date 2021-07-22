//
//

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct
{
    int a[MAX];
    int front,rear;
}Queue;

//isEmpty function
int isEmpty(int front)
{
    if(front==-1)
        return 1;
    else
        return 0;
}

//Dequeue function to dequeue a vertex from the queue*/
int dequeue(Queue *q)
{
    
    int x=q->a[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else
     {
         q->front++;
     }
    return x;
}

/* Queue to hold the vertices with in-degree zero*/
void enqueue(Queue *q, int e)
{

    q->rear++;
    q->a[q->rear]=e;
    if(q->front==-1)
    {
        q->front=0;
    }
}

/*Create graph in adjacency matrix form*/
void creategraph(int adjMatrix[][MAX],int V){
    //instructor missed int on the above line
    int i, j;
    for (i=1;i<=V;i++){
        for(j=1;j<=V; j++){
            adjMatrix[i][j]=0;//initialize all values as zero, meaning there is no edge
        }
    }
}

/*Function to add edges from source to destination*/
void addEdge(int adjMatrix[][MAX], int src, int dest){
    adjMatrix[src][dest]=1; //update from 0 to 1
}

/*Print the adjacency matrix of the Graph*/
void printAdjMatrix(int adjMatrix[][MAX],int V){
    int i,j;
    for (i=1;i<=V;i++){
        for(j=1;j<=V; j++){
            printf("     %d",adjMatrix[i][j]);
        }
        printf("\n");
    }
}



/*calculate the indegree of each vertex by looping through all vertices and edges in the adjacency matrix*/
int find_indegree(int arr[][MAX], int node)
{
    int i,in_deg = 0;
    int n=7;
    for (i =1;i <=n;i++)
    {
       if(arr[i][node] == 1)
        in_deg++;
    }
    return in_deg;
    
}
/*Function to perform topological sorting of the Graph */
void topologicalOrder(int arr[][50], Queue *t, int n)
{
    int j=0,del_node,i;
    //j is the index for result[]
    //i is the index to traverse neighbor
    int result[MAX],indeg[MAX];

    //Insert your code here

    // 1.Put the nodes with zero indegree in a queue.
    // Check all nodes from 1 to n to find the indegree.
    // Call find_indegree function and assign it to indeg array
    // Check if indegree of that node is zero, if it is zero call enqueue function.
    // 1. 把每一個node的indegree都用一個arraylist記錄下來：indegree[0][1][2][1][0][1]
           
    for (i=1; i<=n; i++) {
        indeg[i] = find_indegree(arr, i);
        if (indeg[i] == 0) {
            enqueue(t, i);
        }
    }
    // 2. 再把所有indegree的node都加入到queue裡，用每個vertex的edge去找它的neighbors
    // 3. while queue(當queue裡還有node)
    //     node=dequeue(q)
    // 2.In this step, we will dequeue the elements and put them into the result array. Also we will update the indegree array.
    // We will perform step 2 when the queue is not empty(t->front).

    int k = 0;
    while(!isEmpty(t->front)) {
        // Call dequeue function and put the deleted node in the result array.Increment the index of the result array.
        result[k] = dequeue(t);
        del_node = result[k];
        k++;
        // check all nodes from 1 to n to remove the edges connected to the deleted node.
        // That is done by checking the arr [del_node][i]==1. If true, remove the edge between the deleted node and its
        // connected nodes, by setting it to zero.
        for (j=1; j<=n; j++){
            if (arr[del_node][j]==1) {
                arr[del_node][j] = 0;       // delete this processed node
            // indeg[del_node] = indeg[del_node] - 1;
            // Decrease the indegree of the vertices directly connected to the deleted node by 1
            indeg[j] = indeg[j] - 1;
                if (indeg[j]==0){
                enqueue(t, j);
                }
            // Again check if the new indegree for the edge node is zero, if it is true,
            // add the edge node to the queue by using enqueue function
            }
        }
    }
    
    printf("\nNodes after topological sorting are:\n");
    for (i=0;i<k;i++){
        printf("%d\t",result[i]);
    }
    printf("\n");
}

/*Main Program*/
int main()
{
    int adjMatrix[50][50];
    int vertices=7;
    Queue t;
    t.front=t.rear=-1;
    creategraph(adjMatrix,vertices);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,2,3);
    addEdge(adjMatrix,2,5);
    addEdge(adjMatrix,2,4);
    addEdge(adjMatrix,3,5);
    addEdge(adjMatrix,4,5);
    addEdge(adjMatrix,5,6);
    addEdge(adjMatrix,7,4);
    printAdjMatrix(adjMatrix,vertices);
    topologicalOrder(adjMatrix, &t,vertices);
   
    return 0;
}

