#include<stdio.h>
#include<stdlib.h>


int* find_gcd(int num1, int num2);
int main(){

	FILE* fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	int num1, num2;

	while (fscanf(fp, "%d %d", &num1, &num2) == 2){
		
		printf("%d %d\n", num1, num2);
		int* arr = find_gcd(num1, num2);

		for (int i = 0; i < 3; i++){
			printf("%d ", arr[i]);
		}
		printf("\n\n");
	}
	

	return 0;
}

int* find_gcd(int num1, int num2){

	
	if (num2 == 0){
		int* value = (int*)malloc(sizeof(int)* 3);
		value[0] = num1;
		value[1] = 1;
		value[2] = 0;

		return value;
	}

	else{

		int* arr = find_gcd(num2, num1 % num2);

		int* value = (int*)malloc(sizeof(int)* 3);
		value[0] = arr[0];
		value[1] = arr[2];
		value[2] = arr[1] - ((num1 / num2)*arr[2]);

		return value;
	}
	
}