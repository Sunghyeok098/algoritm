//201534103 ha sung hyeok
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void find_matrix(struct Node* ob, int num);
void primMST(float** graph, int num);
void printMST(int* parent, int num, float** graph);
int minkey(int* key, bool* mstSet, int num);

struct Node{
	int index;
	float x;
	float y;
};

int main(){

	FILE* fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	int num;
	while (fscanf(fp, "%d", &num) == 1){

		struct Node* ob = (struct Node*)malloc(sizeof(struct Node) * num);

		for (int i = 0; i < num; i++){
			fscanf(fp, "%f %f", &ob[i].x, &ob[i].y);
			ob[i].index = i;
		}

		find_matrix(ob, num);
		free(ob);
	}

	fclose(fp);
	return 0;
}

void find_matrix(struct Node* ob, int num){
	
	float** graph;
	graph = (float**)malloc(sizeof(float*)*num);
	
	for (int i = 0; i < num; i++){
		graph[i] = (float*)malloc(sizeof(float)*num);
	}

	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < num; i++){
		for (int j = 0; j < num; j++){
			if (i == j){
				continue;
			}

			else{
				float distince = sqrt((ob[i].x - ob[j].x)*(ob[i].x - ob[j].x) + (ob[i].y - ob[j].y)*(ob[i].y - ob[j].y));
				graph[i][j] = distince;
			}
		}
	}
	primMST(graph, num);
	 
	for (int i = 0; i < num; i++){
		free(graph[i]);
	}
	free(graph);
}

void primMST(float** graph, int num){

	int* parent = (int*)malloc(sizeof(int)*num);
	int* key = (int*)malloc(sizeof(int)*num);
	bool* mstSet = (bool*)malloc(sizeof(bool)*num);

	for (int i = 0; i < num; i++){
		key[i] = INT_MAX, mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < num - 1; i++){

		int u = minkey(key, mstSet, num);
		mstSet[u] = true;

		for (int j = 0; j < num; j++){

			if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j]){
				parent[j] = u, key[j] = graph[u][j];
			}
		}
	}

	printMST(parent, num, graph);
}

int minkey(int* key, bool* mstSet, int num){

	int min = INT_MAX, min_index;

	for (int i = 0; i < num; i++){
		if (mstSet[i] == false && key[i] < min){
			min = key[i], min_index = i;
		}
	}

	return min_index;
}

void printMST(int* parent, int num, float** graph){

	float sum = 0;

	for (int i = 1; i < num; i++){
		sum = sum + graph[i][parent[i]];
	}

	printf("%.2f\n", sum);
}