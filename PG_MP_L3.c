/*
* określanie funkcji prawdopodobieństwa
* Metoda odwracania dystrybuanty
* generowanie 100000 liczb 
* do y - rand();
* zad 1:
* x = 1   2   3   4
* y = 0.3 0.4 0.1 0.2
* zad 2:
* całka i wzór
* wyprowadzić funkcje odwrotną do całki
* od 50 do 150
* funkcja stała
* całka ze stałej to funkcja liniowa
* 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int z1() {
	double div = RAND_MAX / 1;
	double y = rand()/div;
	
	if(y <= 0.3)
		return 1;
	else if(y <= 0.7)
		return 2;
	else if(y <= 0.8)
		return 3;
	else
		return 4;
} 
double F(double x) {
	return 100*x + 50;
}
int z2() {
	double div = RAND_MAX / 1;
	double x = rand()/div;
	return F(x);
}

int main() {
	srand(time(NULL));
	
	// zad 1
	printf("zad 1:\n");
	unsigned int Z1[4] = {0,0,0,0}, Z2[10] = {0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < 100000; i++)
		Z1[z1()-1]++;
	for(int i = 0; i < 4; i++)
		printf("%d - %u\n", i+1, Z1[i]);
		
	// zad 2
	printf("zad 2:\n");
	for (int i = 0; i < 100000; i++) {
		double x = z2();
		int idx = (int)(x - 50)%10;
		Z2[idx]++;
		
	}
	for(int i = 0; i < 10; i++)
		printf("%d - %u\n", 1, Z2[i]);
		
	return 0;
}
