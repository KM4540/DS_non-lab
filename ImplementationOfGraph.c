#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int V; // Number of vertices
    struct Node** adjList; // Array of adjacency lists
};

// Function to create a new graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists of size V
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    // Initialize each adjacency list as empty (NULL)
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to add an edge to an undirected graph
void addEdgeUndirected(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    addEdge(graph, src, dest);

    // Since it's an undirected graph, add an edge from dest to src as well
    addEdge(graph, dest, src);
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* currentNode = graph->adjList[i];
        printf("Adjacency list of vertex %d: ", i);
        while (currentNode != NULL) {
            printf("%d -> ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 5;
    struct Graph* directedGraph = createGraph(V);
    addEdge(directedGraph, 0, 1);
    addEdge(directedGraph, 0, 2);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 2, 3);
    addEdge(directedGraph, 3, 4);

    printf("Directed Graph:\n");
    printGraph(directedGraph);

    struct Graph* undirectedGraph = createGraph(V);
    addEdgeUndirected(undirectedGraph, 0, 1);
    addEdgeUndirected(undirectedGraph, 0, 2);
    addEdgeUndirected(undirectedGraph, 1, 2);
    addEdgeUndirected(undirectedGraph, 2, 3);
    addEdgeUndirected(undirectedGraph, 3, 4);

    printf("Undirected Graph:\n");
    printGraph(undirectedGraph);

    return 0;
}
