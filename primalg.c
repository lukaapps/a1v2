#include "primalg.h"
#include <stdlib.h>
#include <assert.h>
#include "graph.h"
#include "pq.h"
#include "adj.h"

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
int prims(struct graph *g, enum problemPart part, int antennaCost, int numVert){
    int num = numVert + 1;
    int * adjMat[num];
    adjacentMatrix(num, g, adjMat);

    struct pq *priority = newPQ();

    int cost = 0;

    for(int i = 0; i<num; i++){
        if(adjMat[0][i] > 0 && adjMat[i][i] == 0){
            int *nodeCopy = malloc(sizeof(int));
            *nodeCopy = i;
            struct edge *move = malloc(sizeof(struct edge));
            move->start = 0;
            move->end = *nodeCopy;
            move->cost = adjMat[0][i];
            enqueue(priority, move, move->cost);
        }
    }
    adjMat[0][0] = -1;

    while(empty(priority) == 0){
        struct edge *move = deletemin(priority);
        int n = move->end;

        if(adjMat[n][n]!=-1){
            switch(part){
                case PART_A:
                    cost+= move->cost;
                    
                case PART_C:
                    if(move->cost > antennaCost){
                        cost+=antennaCost;
                    }
                    else{
                        cost += move->cost;
                    }
            
            }
            
            adjMat[n][n] = -1;
            for(int i = 0; i<num; i++){
                if(adjMat[0][i] > 0 && adjMat[i][i] == 0){
                    int *nodeCopy = malloc(sizeof(int));
                    *nodeCopy = i;
                    struct edge *move = malloc(sizeof(struct edge));
                    move->start = 0;
                    move->end = *nodeCopy;
                    move->cost = adjMat[0][i];
                    enqueue(priority, move, move->cost);
                }
            }

  
        }
        free(move);
    }
    freeMat(num, adjMat);
    freePQ(priority);
    return cost;


}

