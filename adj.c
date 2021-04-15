#include "adj.h"
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "pq.h"

struct edge;

/* Definition of a graph. */
struct graph {
  int numVertices;
  int numEdges;
  int allocedEdges;
  struct edge **edgeList;
};

/* Definition of an edge. */
struct edge {
  int start;
  int end;
  int cost;
};

void adjacentMatrix(int num, struct graph *g, int * adjMat[]){
    int i;
    //Assigning memory to the adjacency matrix
    for (i = 0; i<num; i++){
        adjMat[i] = (int *) malloc((num) * sizeof(int));
    }
    //similar to the add edge function in graph.c we will create a two dimensional adj matrix
    for (i =0; i<g->numEdges;i++){
        int start = g->edgeList[i]->start;
        int end = g->edgeList[i]->end;
        int cost = g->edgeList[i]->cost;
        //We get the trailing value to assess if the next edge exists 
        int trailValue = adjMat[start][end];
        if((trailValue > 0 && cost < trailValue)||trailValue == 0){
            adjMat[start][end] = cost;
            adjMat[end][start] = cost;

        }

    }
 
}
void freeMat(int num, int * adjMat[]){
    for(int i =0; i<num; i++){
        free(adjMat[i]);
    }
}
