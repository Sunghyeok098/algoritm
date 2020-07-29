//201534103 HA SUNG HYEOK
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE* fp;
char city_name[100][100];
int city_num;
int train_num;
int depart;
int start;
int end;
int schedule_num[1000];
int train[1000][100][2];
int min_time[100][2];
int check[100];
int city_location(char *name);

int input();
void scheduler();


int main(){

	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	int num;
	fscanf(fp, "%d", &num);

	for (int i = 0; i < num; i++){

		if (input() == -1){
			printf("start and arrival equal.\n");
			return 0;
		}

		scheduler();

		if (check[end]){

			printf("----------------------\n");
			printf("Departure : %04d %s\n", min_time[start][1], city_name[start]);
			printf("Arrival   : %4d %s\n", min_time[end][0], city_name[end]);
		}

		else{
			printf("No Connection");
		}
			
	}

	fclose(fp);
	return 0;
}

int input(){

	char name[100];
	fscanf(fp, "%d", &city_num);

	for (int i = 0; i < city_num; i++){
		fscanf(fp, "%s", city_name[i]);
	}

	fscanf(fp, "%d", &train_num);

	for (int i = 0; i < train_num; i++){

		fscanf(fp, "%d", &schedule_num[i]);
		for (int j = 0; j < schedule_num[i]; j++){

			fscanf(fp, "%d %s", &train[i][j][0], name);
			train[i][j][1] = city_location(name);

		}
	}

	fscanf(fp, "%d", &depart);
	fscanf(fp, "%s", name);
	start = city_location(name);
	fscanf(fp, "%s", name);
	end = city_location(name);

	if (start == end){
		return -1;
	}

	return 0;
}


int city_location(char *name){

	int i;

	for (i = 0; i < city_num; i++){

		if (strcmp(name, city_name[i]) == 0){
			return i;
		}
	}

	return -1;
}


void scheduler(){

	int l;
	int now;

	for (int i = 0; i < train_num; i++){
		min_time[i][0] = 10000;
		min_time[i][1] = -1;
		check[i] = 0;
	}


	min_time[start][0] = depart;

	for (int i = 0; i < train_num; i++){
		now = -1;

		for (int j = 0; j < train_num; j++){

			if (check[j]){
				continue;
			}
				
			if (now == -1 || min_time[now][0] > min_time[j][0]){
				now = j;
			}
				
		}

		if (min_time[now][0] == 10000){
			break;
		}
		
		check[now] = -1; 

		for (int j = 0; j < train_num; j++){

			for (int k = 0; k < schedule_num[j] - 1; k++){

				if (train[j][k][1] == now && min_time[now][0] <= train[j][k][0]){
			
					l = k + 1;

					if (min_time[train[j][l][1]][0] > train[j][l][0]){
						min_time[train[j][l][1]][0] = train[j][l][0];
					}
						
				}
			}
		}
	}


	if (check[end] == 0){
		return;
	}

	for (int i = 0; i < city_num; i++){
		check[i] = 0;
	}
		

	min_time[end][1] = min_time[end][0];

	for (int i = 0; i < city_num; i++){

		now = -1;
		for (int j = 0; j < city_num; j++){

			if (check[j]){
				continue;
			}
				
			if (now == -1 || min_time[now][1] < min_time[j][1]){
				now = j;
			}
		}

		check[now] = 1;

		for (int j = 0; j < train_num; j++){

			for (int k = 1; k < schedule_num[j]; k++){

				if (train[j][k][1] == now && min_time[now][1] >= train[j][k][0]){

					l = k - 1;
					if (min_time[train[j][l][1]][1] < train[j][l][0]){

						min_time[train[j][l][1]][1] = train[j][l][0];
					}
				}
			}
		}
	}
}
