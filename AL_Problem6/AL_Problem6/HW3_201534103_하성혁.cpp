//201534103 ha sung hyeok
#include <stdio.h>
#include <stdlib.h>

int row, col;
int** arr;
int** cost;

void find_Cheapest();
void cost_arr();
int find_Min();

int main(){

	FILE* fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	int num;

	while (fscanf(fp, "%d %d", &row, &col) == 2){

		arr = (int **)malloc(sizeof(int*)*row);

		for (int i = 0; i < row; i++){
			arr[i] = (int *)malloc(sizeof(int)*col);
		}

		cost = (int **)malloc(sizeof(int*)*row);

		for (int i = 0; i < row; i++){
			cost[i] = (int *)malloc(sizeof(int)*col);
		}

		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				fscanf(fp, "%d", &num);
				arr[i][j] = num;
			}
		}

		cost_arr();
		find_Cheapest();

		free(arr);
		free(cost);

	}

	fclose(fp);
	return 0;
}

void cost_arr(){

	int temp;

	for (int i = 0; i < row; i++){
		cost[i][0] = arr[i][0];
	}


	for (int i = 0; i < col - 1; i++){

		for (int j = 0; j < row; j++) {

			if (j == 0){
				cost[row - 1][i + 1] = arr[row - 1][i + 1] + cost[j][i];
				cost[j][i + 1] = arr[j][i + 1] + cost[j][i];
				cost[j + 1][i + 1] = arr[j + 1][i + 1] + cost[j][i];
			}

			else if (j == row - 1){

				temp = arr[j - 1][i + 1] + cost[j][i];

				if (temp < cost[j - 1][i + 1]){
					cost[j - 1][i + 1] = temp;
				}

				temp = arr[j][i + 1] + cost[j][i];

				if (temp < cost[j][i + 1]){
					cost[j][i + 1] = temp;
				}

				temp = arr[0][i + 1] + cost[j][i];

				if (temp < cost[0][i + 1]){
					cost[0][i + 1] = temp;
				}

			}

			else{
				temp = arr[j - 1][i + 1] + cost[j][i];

				if (temp < cost[j - 1][i + 1]){
					cost[j - 1][i + 1] = temp;
				}

				temp = arr[j][i + 1] + cost[j][i];

				if (temp < cost[j][i + 1]){
					cost[j][i + 1] = temp;
				}

				if (j == row - 2){
					temp = arr[j + 1][i + 1] + cost[j][i];

					if (temp < cost[j + 1][i + 1]){
						cost[j + 1][i + 1] = temp;
					}

				}
				else{
					cost[j + 1][i + 1] = arr[j + 1][i + 1] + cost[j][i];
				}
			}
		}
	}
}

int find_Min(){

	int i;
	int min = 0;

	for (i = 1; i < row; i++){

		if (cost[i][col - 1] < cost[min][col - 1]){
			min = i;
		}
	}

	return min;
}

int find_MinValue(int x, int y, int z, int n){


	int min;
	int temp[3];
	temp[0] = x;
	temp[1] = y;
	temp[2] = z;

	for (int i = 0; i < 3; i++){

		if (i == 0){
			min = temp[i];
		}

		else{
			if (cost[min][n] > cost[temp[i]][n]){
				min = temp[i];
			}

		}
	}

	return min;
}

void find_Cheapest(){

	int* index;
	int posX;
	int temp[3];

	index = (int *)malloc(sizeof(int)*col);
	posX = find_Min();
	printf("Cheapest Cost : %d\n", cost[posX][col - 1]);
	index[col - 1] = arr[posX][col - 1];

	for (int i = col - 2; i >= 0; i--){

		if (posX == 0){
			temp[0] = row - 1;
			temp[1] = posX;
			temp[2] = posX + 1;
		}

		else if (posX == row - 1){
			temp[0] = 0;
			temp[1] = posX;
			temp[2] = posX - 1;
		}

		else{
			temp[0] = posX - 1;
			temp[1] = posX;
			temp[2] = posX + 1;
		}
		posX = find_MinValue(temp[0], temp[1], temp[2], i);
		index[i] = arr[posX][i];

	}

	for (int i = 0; i < col; i++){
		printf("%d ", index[i]);
	}

	printf("\n");
	free(index);
}