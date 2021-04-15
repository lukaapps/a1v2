#include "pq.h"
#include "graph.h"

void adjacentMatrix(int num, struct graph *g, int * adjMat[]);

void freeMat(int num, int * adjMat[]);

int prims(struct graph *g, enum problemPart part, int antennaCost, int numVert);