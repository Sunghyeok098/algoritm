//201534103 ha sung hyeok
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	FILE* fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}
	int case_count = 1;
	int count = 0;
	int tot_num;
	int num1, num2, cost1, cost2;
	int tot_cost = 0;

	while (fscanf(fp, "%d", &tot_num) == 1){

		if (tot_num == 0){
			break;
		}

		fscanf(fp, "%d %d %d %d", &cost1, &num1, &cost2, &num2);


		while (1){

			if (tot_num % num1 == 0 || tot_num % num2 == 0){
				int min1 = tot_num / num1 * cost1;
				int min2 = tot_num / num2 * cost2;
				
				if (min1 < min2){
					printf("case %d : %d %d\n", case_count, tot_num/num1, 0);
				}
				else{
					printf("case %d : %d %d\n", case_count, 0, tot_num / num2);
				}
				break;
			}

			else{
				int count = tot_num;
				int a, b;

				if (cost1 < cost2){
					a = count / num1;
					count = count % num1;
					b = count / num2;

					for (int i = 1; i <= a; i++){

						a = a - i;
						b = b + i;

						if (tot_num == ((a*num1) + (b*num2))){
							printf("case %d : %d %d\n", case_count, a, b);
							tot_num = 0;
							break;
						}

					}
					if (tot_num != 0){
						printf("case %d : Failed.\n", case_count);
						break;
					}

					else{
						break;
					}
				}

				else{
					a = count / num2;
					count = count % num2;
					b = count / num1;

					for (int i = 1; i <= a; i++){

						a = a - i;
						b = b + i;

						if (tot_num == ((a*num2) + (b*num1))){
							printf("case %d : %d %d\n", case_count, b, a);
							tot_num = 0;
							break;
						}

					}
					if (tot_num != 0){
						printf("case %d : Failed.\n", case_count);
						break;
					}

					else{
						break;
					}
				}	
			}
		}

		case_count++;
	}

	fclose(fp);
	return 0;
}

