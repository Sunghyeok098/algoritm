//201534103 Ha Sunghyeok
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n_queen(int* mat, int n);
int promising(int* mat, int k);

int main(){

	int n;

	printf("Enter the N : ");
	scanf("%d", &n);

	int* mat;

	mat = (int*)malloc(sizeof(int)*n);

	printf("%d\n", n_queen(mat, n));

	return 0;
}

int n_queen(int* mat, int n){

	int count = 0;
	int k = 1;
	mat[k] = 0; 

	while (k != 0){

		mat[k] = mat[k] + 1;

		while ((mat[k] <= n) && !promising(mat, k)){
			mat[k]++;
		}
			
		if (mat[k] <= n){

			if (k == n){
				count++;
			}
				
			else{
				k++;
				mat[k] = 0;
			}
		}
		else{
			k--;
		}
			
	}

	return count;
}
 
int promising(int* mat, int k){

	
	for (int i = 1; i < k; i++){

		if ((mat[i] == mat[k]) || ((abs(mat[i] - mat[k]) == abs(i - k)))){
			return 0;
		}
			
	}

	return 1;
}