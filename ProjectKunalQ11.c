//bfs and dfs 
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

int visited[MAX_VERTICES];

int queue[MAX_VERTICES];
int front = -1;
int rear = -1;

// Function to add an edge to the graph
void add_edge(int source, int destination) {
  adjacency_matrix[source][destination] = 1;
  adjacency_matrix[destination][source] = 1;
}

// Function to initialize the visited array
void initialize_visited() {
  for (int i = 0; i < MAX_VERTICES; i++) {
    visited[i] = 0;
  }
}

// Function to perform a DFS traversal
void dfs(int vertex) {
  visited[vertex] = 1;
  printf("%d ", vertex);

  for (int i = 0; i < MAX_VERTICES; i++) {
    if (adjacency_matrix[vertex][i] == 1 && visited[i] == 0) {
      dfs(i);
    }
  }
}

// Function to perform a BFS traversal
void bfs(int vertex) {
  visited[vertex] = 1;
  enqueue(vertex);

  while (!is_empty()) {
    int current_vertex = dequeue();
    printf("%d ", current_vertex);

    for (int i = 0; i < MAX_VERTICES; i++) {
      if (adjacency_matrix[current_vertex][i] == 1 && visited[i] == 0) {
        visited[i] = 1;
        enqueue(i);
      }
    }
  }
}

// Function to enqueue an element into the queue
void enqueue(int element) {
  if (rear == MAX_VERTICES - 1) {
    printf("Queue is full\n");
    return;
  }

  rear++;
  queue[rear] = element;
}

// Function to dequeue an element from the queue
int dequeue() {
  if (front == rear) {
    printf("Queue is empty\n");
    return -1;
  }

  front++;
  return queue[front];
}

// Function to check if the queue is empty
int is_empty() {
  return front == rear;
}

// Main function
int main() {
  // Initialize the adjacency matrix
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      adjacency_matrix[i][j] = 0;
    }
  }

  // Add some edges to the graph
  add_edge(0, 1);
  add_edge(0, 2);
  add_edge(1, 3);
  add_edge(1, 4);
  add_edge(2, 5);
  add_edge(2, 6);

  // Display the menu
  printf("Menu:\n");
  printf("1. DFS\n");
  printf("2. BFS\n");
  printf("3. Exit\n");

  // Get the user's choice
  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform the selected operation
  switch (choice) {
    case 1:
      // Perform DFS
      initialize_visited();
      dfs(0);
      break;
    case 2:
      // Perform BFS
      initialize_visited();
      bfs(0);
      break;
    case 3:
      // Exit the program
      exit(0);
    default:
      printf("Invalid choice\n");
  }

  return 0;
}