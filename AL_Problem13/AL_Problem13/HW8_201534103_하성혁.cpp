#include<stdio.h>
#include<stdlib.h>

int find_e(unsigned long long phi);
int find_d(unsigned long long phi, unsigned long long e, unsigned long long n);
int find_c(unsigned long long m, unsigned long long n, unsigned long long e);

int main(){

	unsigned long long p, q;
	unsigned long long n, phi;
	//printf("Enter p and q : ");
	//scanf("%d %d", &p, &q);
	p = 3;
	q = 5;

	u printf("p : %llu\nq : %llu\n", p, q);
	n = p*q;
	phi = (p - 1)*(q - 1);
	printf("n : %llu\n", n);
	printf("phi(%llu) : %llu\n", n, phi);

	unsigned long long e = find_e(phi);
	printf("e : %llu\n", e);
	
	unsigned long long d = find_d(phi, e, n);
	printf("d : %llu\n", d);
		
	unsigned long long c = find_c(13, n, e);
	unsigned long long m = find_c(c, n, d);

	printf("c : %llu\n", c);
	printf("m : %llu\n", m);

	return 0;
}

int find_e(unsigned long long phi){

	for (unsigned long long i = 2; i <= phi; i++){
		
		if (phi % i != 0){
			return i;
		}
	}
}

int find_d(unsigned long long phi, unsigned long long e, unsigned long long n){

	unsigned long long i = phi + 1;

	for (unsigned long long i = 1; i < n; i++){

		if (((e * i) % phi) == 1){
			return i;
		}
	}
}

int find_c(unsigned long long m, unsigned long long n, unsigned long long e){
	
	unsigned long long result = 1;

	for (int i = 0; i < e; i++){
		
		result = result * m;
	}
	
	return result % n;
}