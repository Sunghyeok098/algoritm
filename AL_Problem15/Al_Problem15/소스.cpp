#include<stdlib.h>
#include<stdio.h>



struct node{

	float x;
	float y;

};

float find_path(struct node* data);

int main(){

	FILE* fp = fopen("input.txt", "r");

	int num;

	fscanf(fp, "%d", &num);

	for (int i = 0; i < num; i++){
		
		int data_num;
		fscanf(fp, "%d", &data_num);

		struct node* data = (struct node*)malloc(sizeof(struct node)*(data_num+1));

		data[0].x = 0;
		data[0].y = 0;

		for (int i = 1; i < data_num + 1; i++){
			fscanf(fp, "%f %f", &data[i].x, &data[i].y);
		}

		for (int i = 0; i < data_num + 1; i++){
			printf("%.1f %.1f\n", data[i].x, data[i].y);
		}


		printf("%.2f\n", find_path(data));
	}

	fclose(fp);
	return 0;
}

float find_path(struct node* data){

	float path_sum = 0;

	

	
	


	return path_sum;
}