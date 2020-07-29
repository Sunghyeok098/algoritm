//
// Algorithm Lab 1
//
// Student ID: 201534103
// Name: Ha Sung Hyeok
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Your code here
// The length of code in MakeOne function is limited by 20 lines
int MakeOne(int n)
{

	if (n == 1)
		return 0;

	else{
		if (n % 2 == 0 && n > 2){
			return 2 + MakeOne(n / 2);
		}

		else if (n % 3 == 0 && n > 4){
			return 4 + MakeOne(n / 3);
		}

		else if (n % 3 != 0 || n % 2 != 0){
			return 1 + MakeOne(n - 1);
		}
	}

	int *p = (int *)malloc((n + 1) * sizeof(int));
	p[0] = p[1] = 0;
	for (int i = 2; i <= n; i++) {
		p[i] = p[i - 1] + 1;
		if (i % 3 == 0)
			p[i] = (p[(int)(i / 3)] + 4 < p[i]) ? p[(int)(i / 3)] + 4 : p[i];
		if (i % 2 == 0) p[i] = (p[(int)(i / 2)] + 2 < p[i]) ? p[(int)(i / 2)] + 2 : p[i];
	}
	int ret_val = p[n];
	free(p);
	return ret_val;
	
}



/*
*
* *********** Caution: Do not modify any code belows *******************
*
*/
int main()
{
	int num = 0;
	clock_t t1, t2;

	while (1) {
		printf("Input a number between 10 and 1000000 (0 to exit):");
		scanf("%d", &num);
		if (num == 0) break;
		if (num < 10 || num > 1000000) continue;

		// Get the number of minimum operation using function of your own
		t1 = clock();
		int min_val = MakeOne(num);
		t2 = clock();

		printf("The minimum cost of operations to make %d to 1 is [%d] \n", num, min_val);
		printf("The Processing time is [%.4f]s (limit 0.1s)\n\n", (float)(t2 - t1) / CLOCKS_PER_SEC);
	}
	return 0;
}