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
    int numberOfVertices;
    struct node** adjLists;
}Graph;

/*A function to create a newnode*/
/*A function to create a graph with an array of adjacency lists which is= numberof vertices*/



    

/*adds an edge to an undirected graph*/
void addConnection(Graph* graph, char* person, char* friend)
{

    //Insert your code here
    
    
    
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
