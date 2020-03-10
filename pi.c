#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415936535
#define P_c 0.7
#define P_m 0.01
#define abs(X) ((X) >= 0 ? (X) : -(X))

double F(int x1, int x2) {		// Funkcja fitness = 1000 - funkcja celu
	double division = (double)x1 / (double)x2;
	division -= PI;
	return abs(division);
}

int cmp(int x, int y) {
	int x1 = (x & 0xFFC00) >> 10; 
	int x2 = (x & 0x3FF);
	int y1 = (y & 0xFFC00) >> 10; 
	int y2 = (y & 0x3FF);
	
	return F(x1, x2) - F(y1,y2);
}

void selekcja(int *tab, int n) {		// Shell sort
	for (int gap = n / 2; gap > 0; gap /= 2)
		for(int i = gap; i < n; i++)
			for (int j = i - gap; j >= 0 && cmp(tab[j], tab[j + gap]) > 0; j -= gap) {
				int temp = tab[j + gap];
				tab[j + gap] = tab[j];
				tab[j] = temp;
			}

}

int *crossover(int *tab, int n, int C, int M) {
	srand(time(NULL));
	int *pt = malloc(n * sizeof *pt);

	for (int i = 0; i < 20; i++)
		pt[i] = tab[i];

	for (int i = 20; i < n; i += 2) {
		int m = rand() % 100;
		for (int j = 0; i < 5; j++) {
			int n = rand() % 100;
			if (n < m)
				m = n;
		}
		int x = tab[m];

		m = rand() % 100;
		for (int j = 0; i < 5; j++) {
			int n = rand() % 100;
			if (n < m)
				m = n;
		}
		int y = tab[m];

		pt[i] = (x & 0xFFC00) + (y & 0x3FF);
		pt[i + 1]  = (y & 0xFFC00) + (x & 0x3FF);
		
		if ((double)rand() / RAND_MAX < M) {
			int tmp = 1;
			tmp <<= rand() % 20 + 1;
			if(pt[i] & tmp)
				pt[i] -= tmp;
			else
				pt[i] += tmp;
		}

		if ((double)rand() / RAND_MAX < M) {
			int tmp = 1;
			tmp <<= rand() % 20 + 1;
			if(pt[i + 1] & tmp)
				pt[i + 1] -= tmp;
			else
				pt[i + 1] += tmp;
		}
	}

	free(tab);
	return pt;
}

int gen() {		// zwraca chromosom;
	int t = 0;
	int *P = malloc(100 * sizeof *P);	// Populacja
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {		// Loswowanie populacji poczatkowej
		P[i] = rand() % 0xFFFFF;
	}
	selekcja(P, 100);

	for (int i = 0; i < 50; i++) {
		t = t + 1;
		P = crossover(P, 100, P_c, P_m);
		selekcja(P, 100);
	}

	return P[0];
}

int main(int argc, char **argv) {
	int x = gen();
	int x1 = (x & 0xFFC00) >> 10; 
	int x2 = (x & 0x3FF);
	
	printf("%d / %d\n", x1, x2);

	return 0;
}
