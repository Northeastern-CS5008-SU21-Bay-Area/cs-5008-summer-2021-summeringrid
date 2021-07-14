// name: Xiaoying Liu
// email: liu.xiaoying@northeastern.edu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 /*structure represents a node to store the names and pointer to next node*/
typedef struct node
{
    char name[50];
    struct node* next;
}node;

/* Structure represents a Graph with an array of adjacency lists.Size of the array will be number of vertices.*/
typedef struct Graph
{
    int numberOfVertices;       // size of the adjlists (size of the linked list)? or how many linked list there is?
    struct node** adjLists;     // pointer to a pointer (double pointer - -|||)
}Graph;

/*A function to create a newnode*/
node* createnode(char *name)        // pointer to the string
{
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}
/*A function to create a graph with an array of adjacency lists which is= numberof vertices*/
Graph* createGraph(int vertices)     // vetices is the number of the nodes
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));       //Q1: why the size is just Graph?
    graph->numberOfVertices = vertices;
    //graph->adjLists = (struct node**)malloc(sizeof(struct node*));      // Q2: can't understand this part :(
    graph->adjLists = (struct node**)malloc(vertices *sizeof(struct node*));        // Q4: malloc for vertices?
    int i;
    for (i = 0; i < graph->numberOfVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
int numberoflists(Graph* graph)
{
    int i, j;
    j = 0;
    for (i = 0; i < graph->numberOfVertices; i++)      //graph->numberOfVertices not vertices..
    {
        if(graph->adjLists[i] != 0)
        j++;
    }
    return j;
}
int search(Graph* graph, char* name)
{
    int i;
    for (i = 0; i < numberoflists(graph); i++)
    {
        if (strcmp(graph->adjLists[i]->name, name)==0)      // compare two strings
            return i;
    }
    return -1;
}
   

/*adds an edge to an undirected graph*/
void addConnection(Graph* graph, char* person, char* friend)
{
    node* newperson = createnode(person);
    node* newfriend = createnode(friend);
    int n = numberoflists(graph);
    int p = search(graph, person);
    //************** Insert your code here
    // check each possibility (adding edges); don't look at slides p11 first, try to figure it out by yourself.
    if (n == 0)
    {
        graph->adjLists[0] = newperson;
        newperson->next = newfriend;
    }
    else
    {
        if (p >= 0)
        {
            node* temp = graph->adjLists[p];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newfriend;
            //todo Q3: how to put temp back to the graph?
        }
        else
        {
            graph->adjLists[n] = newperson;
            newperson->next = newfriend;
        }
    }
    
    
}

//function to print the adjacency list representation of a graph
void printGraph(Graph* graph)
{
    int i;
    for (i = 0; i<graph->numberOfVertices;i++)
    {
    //print the current vertex and all its neighbors
    struct node* temp = graph->adjLists[i];
    printf("\n%s---",graph->adjLists[i]->name );
    while((temp->next)!=NULL)
    {
    printf("%s-", temp->next->name);
    temp = temp->next;
    }
    printf("NULL\n");
    }
}

/*---------CONVERSION TO MATRIX------*/
int getIndex(Graph* graph, char* name)
{
    int N = graph->numberOfVertices;
    int i,j=0;
    for (i = 0; i<N&& strcmp(name,graph->adjLists[i]->name)!=0 ;i++)
    {
        j++;
    }
    return j;
}

void Matrixform(Graph* graph, int emptyMatrix[50][50],int N)
{
    int i,j;
    for (i = 0; i<N;i++){
    struct node* temp = graph->adjLists[i]->next;
    while (temp)
    {
    j = getIndex(graph, temp->name);
    emptyMatrix[i][j] = 1;
    temp = temp->next;
    }
    }
}
/* Destroy the graph by freeing adjlists and graph*/
void graph_destroy(Graph *graph)
{
    int i;
    for(i=0; i<graph->numberOfVertices;i++)
    
        free(graph->adjLists[i]);
        free(graph);
    }
/* Print the graph in matrix form */
void printMatrix(int matrix[50][50], Graph* graph)
{
    int row,col,nodes=graph->numberOfVertices;
    printf("\nAdjacent matrix:\n");
    printf("        ");
    for (col = 0; col < nodes; col++)
    {
    printf("%6s ", graph->adjLists[col]->name);
    }
    printf("\n");
    for (col = 0; col < nodes; col++)
    {
    printf("-------------");
    }
    printf("\n");
    for (row = 0; row < nodes; row++) {
    printf("%7s| ", graph->adjLists[row]->name);
    for (col = 0; col < nodes; col++) {
    printf("  %2d    ", matrix[row][col]);
    }
    printf("\n");
    }

}

/*------Main Program------------*/
int main()
{
    
    int k, z,Num=7;
    //construct a graph
    Graph* graph = createGraph(Num);
    char person[50];
    char friend[50];
    addConnection(graph, "personA", "personB");
    addConnection(graph, "personA", "personG");
    addConnection(graph, "personA", "personE");
    addConnection(graph, "personB", "personA");
    addConnection(graph, "personB", "personE");
    addConnection(graph, "personB", "personC");
    addConnection(graph, "personB", "personG");
    addConnection(graph, "personC", "personB");
    addConnection(graph, "personC", "personD");
    addConnection(graph, "personC", "personE");
    addConnection(graph, "personD", "personC");
    addConnection(graph, "personD", "personE");
    addConnection(graph, "personD", "personF");
    addConnection(graph, "personE", "personA");
    addConnection(graph, "personE", "personB");
    addConnection(graph, "personE", "personC");
    addConnection(graph, "personE", "personD");
    addConnection(graph, "personE", "personF");
    addConnection(graph, "personE", "personG");
    addConnection(graph, "personF", "personE");
    addConnection(graph, "personF", "personG");
    addConnection(graph, "personF", "personD");
    addConnection(graph, "personG", "personB");
    addConnection(graph, "personG", "personA");
    addConnection(graph, "personG", "personE");
    addConnection(graph, "personG", "personF");
    
    //function to print the adjacency list representation of a graph
    printGraph(graph);
    int N = graph->numberOfVertices, i,j;
    int adj_matrix[50][50];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            adj_matrix[i][j] = 0;
        }
        
    }
    Matrixform(graph, adj_matrix, N);
    printMatrix(adj_matrix, graph);
    graph_destroy(graph);
}


