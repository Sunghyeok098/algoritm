//201534103 Ha Sung Hyeok
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000
char** city;
int** graph;
int city_num;

int find_cost(int start, int end);
int minkey(int key[], bool vertexSet[], int end);

int main(){


	FILE* fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	
	fscanf(fp, "%d", &city_num);

	city = (char**)malloc(sizeof(char)*city_num);
	for (int i = 0; i < city_num; i++){
		city[i] = (char*)malloc(sizeof(char)* 100);
	}

	char city_name[100];
	for (int i = 0; i < city_num; i++){
		fscanf(fp, "%s", city[i]);
	}

	int num;
	fscanf(fp, "%d", &num);

	graph = (int**)malloc(sizeof(int)*city_num);
	for (int i = 0; i < city_num; i++){
		graph[i] = (int*)malloc(sizeof(int)* city_num);
	}

	for (int i = 0; i < city_num; i++){
		for (int j = 0; j < city_num; j++){
			graph[i][j] = MAX;
		}
	}

	int row, col, cost;
	for (int i = 0; i < num; i++){
		fscanf(fp, "%d %d %d", &row, &col, &cost);
		graph[row - 1][col - 1] = cost;
	}
	
	int q_num;
	int start, end;
	fscanf(fp, "%d", &q_num);

	for (int i = 0; i < q_num; i++){
		fscanf(fp, "%d %d", &start, &end);

		if (start != 0){
			printf("%s %s %d\n", city[start - 1], city[end - 1], find_cost(start, end));
		}

		else{
			printf("%s %s %d\n", city[start], city[end - 1], 0);
		}
		
	}

	fclose(fp);
	return 0;
}

int find_cost(int start, int end){

	int* parent = (int*)malloc(sizeof(int)*city_num);
	int* key = (int*)malloc(sizeof(int)*city_num);
	bool* vertexSet = (bool*)malloc(sizeof(bool)*city_num);

	int cost = 0;

	for (int i = 0; i < city_num; i++){
		key[i] = MAX, vertexSet[i] = false;
	}

	for (int i = 0; i < city_num; i++){
		key[i] = graph[start - 1][i];
	}
	
	parent[0] = -1;

	for (int i = 0; i < city_num - 1; i++){

		int u = minkey(key, vertexSet, end);
		cost = cost + key[u];
		vertexSet[u] = true;
		if (vertexSet[end - 1] == true){
			break;
		}

		for (int j = 0; j < city_num; j++){
			
			if (graph[u][j] && vertexSet[j] == false && graph[u][j] < key[j]){
				parent[j] = u;
				key[j] = graph[u][j];
			}
		}
	}

	return cost;
}

int minkey(int key[], bool vertexSet[], int end){

	int min = MAX;
	int	min_index;

	for (int i = 0; i < city_num; i++){
		if (key[end-1] != MAX){
			return end - 1;
		}
		if (vertexSet[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		}
	}

	return min_index;
}


