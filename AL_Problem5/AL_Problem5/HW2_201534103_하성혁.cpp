//201534103 ha sung hyeok
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define first_size 10000
#define second_size 100

int function(char* str1, char* str2);
int main(){

	FILE* fp;
	fp = fopen("input.txt", "r");

	if (fp == NULL){
		printf("File not exist.\n");
		return -1;
	}

	else{
		char str[first_size];

		int distinct_sequence;
		int count = 0;
		while (fgets(str, sizeof(str), fp)){

			char str1[first_size];
			char str2[second_size];

			if (atoi(str) != 0){
				printf("Test case Number : %d\n", atoi(str));
			}

			else{
		
				if (count % 2 == 1){
					strcpy(str1, str);
				}
				else{
					distinct_sequence = 0;
					//strcpy(str2, str);
					//printf("%s%s\n", str1, str2);
					distinct_sequence = function(str1, str);

					printf("distinct_sequence : %d\n", distinct_sequence);
				}

			}
			count++;
			
		}

	}
	
	fclose(fp);
	return 0;
}

int function(char* str1, char* str2){

	printf("%d\n", strlen(str2));
	int count = 0;
	if (strlen(str2) == 2 ){
		count = 0;
		
		for (int i = 0; i < strlen(str1); i++){
			
			if (str1[i] == str2[0]){
				
				count++;
			}
			
		}
		return count;
	}

	else{

		for (int i = 0; i < strlen(str1); i++){
			
			if (str1[i] == str2[0]){

				char* sub_str1 = (char*)malloc(sizeof(str1));
				char* sub_str2 = (char*)malloc(sizeof(str2));

				int a = 0;
				for (a = 0; a < strlen(str1); a++){
					sub_str1[a] = str1[a + i + 1];

				}
				sub_str1[a] = '\0';
				for (a = 0; a < strlen(str2); a++){
					sub_str2[a] = str2[a + 1];
				}

				sub_str2[a] = '\0';

				count = count + function(sub_str1, sub_str2);

			}
			
		}
	}
	
	return count;
	
}