//201534103 Ha Sunghyeok
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 99999

struct point{

	float x;
	float y;
};

float closest(struct point* data, int num);
float min(float dl, float dr);
float brute_force(struct point* data, int num);
float dist(struct point data1, struct point data2);
float stripClosest(struct point* strip, int size, float d);

int main(){

	FILE* fp = fopen("input.txt", "r");

	int num;
	fscanf(fp, "%d", &num);

	struct point* data = (struct point*)malloc(sizeof(struct point)*num);

	for (int i = 0; i < num; i++){
		fscanf(fp, "%f %f", &data[i].x, &data[i].y);
	}

	for (int i = 0; i < num; i++){
		printf("%.1f %.1f\n", data[i].x, data[i].y);
	}

	for (int i = 0; i < num - 1; i++){
		 
		int min = i;

		for (int j = i + 1; j < num; j++){
			if (data[min].x > data[j].x){
				min = j;
			}
		}
		struct point temp = data[i];
		data[i] = data[min];
		data[min] = temp;
	}

	for (int i = 0; i < num; i++){
		printf("%.1f %.1f\n", data[i].x, data[i].y);
	}

	float dist = closest(data, num);

	if (dist < 10000){
		printf("%f\n", dist);
	}
	else{
		printf("Infinity.\n");
	}

	fclose(fp);
	return 0;
}

float closest(struct point* data, int num){

	if (num <= 3){
		return brute_force(data, num);
	}

	int mid = num / 2;
	struct point midPoint = data[mid];

	float dl = closest(data, mid);
	float dr = closest(data + mid, num-mid);

	float d = min(dl , dr);

	struct point* strip = (struct point*)malloc(sizeof(struct point)*num); 

	int j = 0;

	for (int i = 0; i < num; i++){

		if (abs(data[i].x - midPoint.x) < d){
			strip[j++] = data[i];
		}
	}

	return min(d, stripClosest(strip, j, d));
	
}

float stripClosest(struct point* strip, int size, float d){

	float min = d; 

	for (int i = 0; i < size - 1; i++){

		int min = i;

		for (int j = i + 1; j < size; j++){
			if (strip[min].y > strip[j].y){
				min = j;
			}
		}
		struct point temp = strip[i];
		strip[i] = strip[min];
		strip[min] = temp;
	}


	for (int i = 0; i < size; ++i){

		for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j){

			if (dist(strip[i], strip[j]) < min){

				min = dist(strip[i], strip[j]);
			}
		}
	}
	
	return min;
}

float min(float dl, float dr){
	
	return dl > dr ? dr : dl;
}

float brute_force(struct point* data, int num){

	float min = MAX;

	for (int i = 0; i < num; ++i){

		for (int j = i + 1; j < num; ++j){

			if (dist(data[i], data[j]) < min){
				min = dist(data[i], data[j]);
			}
		}
	}
	
	return min;
}

float dist(struct point data1, struct point data2){

	return sqrt((data1.x - data2.x)*(data1.x - data2.x) + (data1.y - data2.y)*(data1.y - data2.y));
}