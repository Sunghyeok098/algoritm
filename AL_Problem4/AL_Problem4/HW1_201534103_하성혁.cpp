//201534103 HA SUNG HYOEK 
#include<stdio.h>
#include<stdlib.h>
#define max_size 1000

void sort(int wight[], int IQ[], int index[], int num);

int main(){

	FILE *fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	else{
		int wight[max_size];
		int IQ[max_size];
		int index[max_size];
		int num = 0; //elephant count
		
		while (fscanf(fp, "%d %d", &wight[num], &IQ[num]) == 2){
			index[num] = num + 1;
			num++;
		}	

		for (int i = 0; i < num; i++){
			printf("%d %d %d\n", index[i], wight[i], IQ[i]);
		}//before sorting

		sort(wight, IQ, index, num);
		printf("\n");

		for (int i = 0; i < num; i++){
			printf("%d %d %d\n", index[i], wight[i], IQ[i]);
		}//after sorting
		
		int max = 0;
		int max_index[max_size];
		int count;
		for (int i = 0; i < num; i++){
			
			count = 1;
			int current_wight = wight[i];
			int current_IQ = IQ[i];
			int k = 0;
			int current_index[max_size];

			for (int j = i + 1; j < num; j++){

				if (k == 0){
					current_index[k++] = index[i];
				}
				
				if (wight[j] > current_wight && IQ[j] < current_IQ){
					count++;
					current_wight = wight[j];
					current_IQ = IQ[j];
					current_index[k++] = index[j];
				}
			}
			if (max < count){
				max = count;
				for (int i = 0; i < count; i++){
					max_index[i] = current_index[i];
				}
				
			}
		}
		printf("Max : %d\n", max);
	
		for (int i = 0; i < max; i++){
			printf("index : %d\n", max_index[i]);
		}
	}
	fclose(fp);
	return 0;
}

void sort(int* wight, int* IQ, int* index, int num){

	for (int i = 0; i < num; i++){
		int min = i;

		for (int j = i + 1; j < num; j++){
			if (wight[min] > wight[j]){
				
				int wight_temp = wight[min];
				wight[min] = wight[j];
				wight[j] = wight_temp;

				int IQ_temp = IQ[min];
				IQ[min] = IQ[j];
				IQ[j] = IQ_temp;

				int index_temp = index[min];
				index[min] = index[j];
				index[j] = index_temp;
			}
		}
	}
	
	for (int i = 0; i < num; i++){
		
		for (int j = i + 1; j < num; j++){
			
			if (wight[i] == wight[j] && IQ[i] < IQ[j]){

				int wight_temp = wight[i];
				wight[i] = wight[j];
				wight[j] = wight_temp;

				int IQ_temp = IQ[i];
				IQ[i] = IQ[j];
				IQ[j] = IQ_temp;

				int index_temp = index[i];
				index[i] = index[j];
				index[j] = index_temp;
			}		
		}
	}
	
}