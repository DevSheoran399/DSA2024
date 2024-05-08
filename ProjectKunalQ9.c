//Graph
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct graph
{
    int numVertices;
    struct node **adjLists;
};

// Function to create a new graph
struct graph *createGraph(int vertices)
{
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct node **)malloc(vertices * sizeof(struct node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct graph *graph, int src, int dest)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = NULL;

    // Add the node to the adjacency list of the source vertex
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function to print the graph
void printGraph(struct graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = graph->adjLists[i];
        printf("\nAdjacency list of vertex %d\n", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to insert a node in the graph
void insertNode(struct graph *graph, int vertex)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = vertex;
    newNode->next = NULL;

    // Add the node to the adjacency list of the vertex
    newNode->next = graph->adjLists[vertex];
    graph->adjLists[vertex] = newNode;
}

// Function to delete a node from the graph
void deleteNode(struct graph *graph, int vertex)
{
    // Find the node to be deleted
    struct node *temp = graph->adjLists[vertex];
    struct node *prev = NULL;

    while (temp != NULL && temp->vertex != vertex)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not found, return
    if (temp == NULL)
    {
        return;
    }

    // If the node is the first node in the adjacency list
    if (prev == NULL)
    {
        graph->adjLists[vertex] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    // Free the memory allocated to the node
    free(temp);
}

// Function to traverse the graph
void traverseGraph(struct graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = graph->adjLists[i];
        printf("\nAdjacency list of vertex %d\n", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main()
{
    // Create a new graph
    struct graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Insert a node in the graph
    insertNode(graph, 5);

    // Delete a node from the graph
    deleteNode(graph, 3);

    // Traverse the graph
    traverseGraph(graph);

    return 0;
}