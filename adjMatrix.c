#include "assignment3.h"

struct Edge ** initAdjMatrix(){
	struct Edge ** adjMatrix = (struct Edge **)malloc(NODES*sizeof(struct Edge*));
        int i = 0, j=0;
        for (i =0; i<NODES; i++){
                adjMatrix[i] = (struct Edge *)malloc(NODES*sizeof(struct Edge));
                for (j =0; j<NODES; j++){
                        adjMatrix[i][j].flow = 0;
                        adjMatrix[i][j].flowCap = 0;
                }
        }
        return adjMatrix;
}

void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap){
	aM[vi][vj].flow = flow;
    aM[vi][vj].flowCap = flowCap;

}

void deleteAdjMatrix(struct Edge ** aM){
	int i = 0;
	for (i =0; i<NODES; i++){
			free(aM[i]);
	}
	free(aM);

}

void printAdjMat(struct Edge ** aM){
	int i, j = 0;
        for (i =0; i< NODES; i++){
                for (j=0; j< NODES; j++){
                        if (aM[i][j].flowCap != 0){
                                printf("Edge: (%d, %d) Flow: %d Max Cap: %d\n", i, j, aM[i][j].flow, aM[i][j].flowCap);
                        }
                }
        }

}
