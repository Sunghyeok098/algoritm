//201534103 Ha SungHyeok
#include<stdio.h>
#include<stdlib.h>

struct cost{

	int time;
	int penalty;
	int index;
	float per_penalty;
};

int main(){

	FILE* fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	struct cost* job;
	int test_num;
	int num_job;
	fscanf(fp, "%d", &test_num);
	printf("test case : %d\n", test_num);
	
	
	for (int i = 0; i < test_num; i++){

		fscanf(fp, "%d", &num_job);
		//printf("number job : %d\n", num_job);
		job = (struct cost*)malloc(sizeof(struct cost)*num_job);
		int count = 1;
		for (int j = 0; j < num_job; j++){
			fscanf(fp, "%d %d", &job[j].time, &job[j].penalty);
			job[j].per_penalty = (float)job[j].penalty / (float)job[j].time;
			job[j].index = count;
			count++;
		}

		for (int j = 0; j < num_job; j++){
			
			int max = j;
			for (int k = j + 1; k < num_job; k++){
				
				if (job[max].per_penalty < job[k].per_penalty){
					max = k;
				}
			}

			struct cost temp = job[j];
			job[j] = job[max];
			job[max] = temp;
		}

		printf("Case %d : ", i+1);
		for (int j = 0; j < num_job; j++){
			printf("%d ", job[j].index);
		}
		printf("\n\n");

		
	}

	

	fclose(fp);
	return 0;
}
