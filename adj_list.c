// Adjacency List representation in C
// adapted from https://www.programiz.com/dsa/graph-adjacency-list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int vertex;
  struct node* next;
};
struct node* create_node(int);

struct graph {
  int numVertices;
  char** labels;
  struct node** Adj;
};

// Create a node
struct node* create_node(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
struct graph* create_graph(int numVertices, char** labels) {
    
  struct graph* G = malloc(sizeof(struct graph));
  G->numVertices = numVertices;
  G->Adj = malloc(numVertices * sizeof(struct node*));
  G->labels = malloc(numVertices * sizeof(char*));
  //printf("memory allocated for graph.\n");
  
  for (int i = 0; i < numVertices; i++) {
    //printf("allocating for label %d\n",i);
    char* alloc_string = malloc((strlen(labels[i])+1) * sizeof(char));   
    strcpy(alloc_string,labels[i]);
    G->labels[i] = alloc_string;
    //printf("allocated and copied");
    G->Adj[i] = NULL;
  }
  return G;
}


// Add edge
void add_edge(struct graph* graph, int s, int t) {
  // Add edge from s to t
  struct node* node = create_node(t);
  node->next = graph->Adj[s];
  graph->Adj[s] = node;

  // Add edge from d to s
  node = create_node(s);
  node->next = graph->Adj[t];
  graph->Adj[t] = node;
}


// Print the graph
void print_graph(struct graph* G) {
  int v;
  for (v = 0; v < G->numVertices; v++) {
    struct node* temp = G->Adj[v];
    printf("\n Vertex %d: %s:\n Adj[%s]", v, G->labels[v],G->labels[v]);
    if(temp) {
      while (temp) {
	int vertex = temp->vertex;
	printf("-> %s ", G->labels[vertex]);
	temp = temp->next;
      }
      printf("-|\n");
    } else {
      printf("-|\n");
    }
  }
}

int main() {
  char* labels[] = {"A", "B", "C", "D", "E"};
  int numVertices = sizeof(labels)/sizeof(labels[0]);
  printf("Creating graph with %d vertices.\n",numVertices);

  struct graph* G = create_graph(numVertices,labels);
  add_edge(G, 0, 1);
  add_edge(G, 0, 2);
  add_edge(G, 0, 3);
  add_edge(G, 1, 2);
  
  print_graph(G);
  
  return 0;
}
