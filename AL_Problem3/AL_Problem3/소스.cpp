#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

int main(){


	FILE* fp;
	fp = fopen("sample.txt", "r");

	if (fp == NULL){
		printf("File not opened.\n");
		return -1;
	}
	
	else{
		char str[size];

		while (fgets(str, sizeof(str), fp)){

			if (atoi(str) == 0){
				printf("End.\n");
				break;
			}
			int str_len = strlen(str);
			int num = atoi(str);
			int* arr = (int*)malloc(sizeof(int)*atoi(str));
			if (str_len == 2){
				
				for (int i = 0; i < num; i++){
					fgets(str, size, fp);
					arr[i] = atoi(str);
				}
			}

			int sum = 0;
			for (int i = 0; i < num; i++){
				sum = sum + arr[i];
			}
			int avg = sum / num;

			int ex_money = 0;
			int b = avg;
			for (int i = 0; i < num; i++){
				
				if (avg % 10 != 0){
					b = avg + (10 - (avg % 10));
				}
	
				int money = 0;
				
				if (arr[i] > b){
					
					int a = avg - (avg % 10);
						
					for (int j = 0; j < num; j++){
						if (arr[j] < a){
							money = a - arr[j];
							arr[j] = arr[j] + money;
							arr[i] = arr[i] - money;
							
							break;
						}
					}
				}
				
				ex_money = ex_money + money;
				
			}
			for (int i = 0; i < num; i++){
				printf("%d ", arr[i]);
			}
			
			printf("\nOutPut : %d\n", ex_money);
		
		}
	
	}
	return 0;
}