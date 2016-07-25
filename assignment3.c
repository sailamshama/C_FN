#include "assignment3.h"

struct flowNetwork * initFlowNetwork(){
	struct flowNetwork* flowNetwork_1 = (struct flowNetwork*)malloc(sizeof(struct flowNetwork));
	flowNetwork_1->adjMatrix = initAdjMatrix();
	int i;
	for (i =0; i<NODES; i++){
			flowNetwork_1->visitedNodes[i] = 0;
			flowNetwork_1->parent[i] = -1;
	}

}

void deleteFlowNetwork(struct flowNetwork * fN){	
	deleteAdjMatrix(fN->adjMatrix);
	free(fN);

}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){
	struct Queue *queue;
        struct Data d, insert_d;
        int i, vertex;

        for (i=0; i<NODES; i++){
                fN->visitedNodes[i] =0;
        }

        initQueue(&queue);
        insert_d.vertex = s;
        enqueue(queue, insert_d);
        while (!isQueueEmpty(queue)){
                dequeue(queue, &d);
                vertex = d.vertex;
                for (i=0; i<NODES;i++){
                	if ((fN->visitedNodes[i] == 0) && fN->adjMatrix[vertex][i].flowCap - fN->adjMatrix[vertex][i].flow > 0){
                        	fN->visitedNodes[i] = 1;
                                fN->parent[i] = vertex;
                                insert_d.vertex = i;
                                enqueue(queue, insert_d);
                                }

                }
        }
        free(queue);
        return fN->visitedNodes[t]; 

}

void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){
	int maxFlow, i, j, parent;
	while (breadthFirstPathSearch(fN, s, t) ==1){
		maxFlow = INF; 
		for (i=t; i!=s; i= fN->parent[i]){
			parent = fN->parent[i];  
			//obtain maximum flow that can be added to the branch
			//i.e. minimum flowCap-flow among the nodes; 
			if (fN->adjMatrix[parent][i].flowCap - fN->adjMatrix[parent][i].flow < maxFlow){
				maxFlow = fN->adjMatrix[parent][i].flowCap - fN->adjMatrix[parent][i].flow;
			}
		} 
		
		//update max-flow
		for (j=t; j!=s; j=fN->parent[j]){ 
			parent = fN->parent[j]; 
			fN->adjMatrix[parent][j].flow += maxFlow; 
		}
	}
}


























