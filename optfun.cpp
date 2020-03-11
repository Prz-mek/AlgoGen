#include <iostream>
#include <ctime>

short F(short x) {		// funkcja fitness
	return 2 * x + 1;
}

short* selskcja(short* tab, int nb, int na) {
	if (nb < na)
		return NULL;
	// Sortowanie
	for (int gap = nb / 2; gap > 0; gap /= 2)
		for (int i = gap; i < nb; i++)
			for (int j = i - gap; j >= 0 && F(tab[j]) > F(tab[j+gap]); j -= gap) {
				short temp = tab[j];
				tab[j] = tab[j+gap];
				tab[j+gap] = temp;
			}
}


short koloBiologicznejFortuny() {

}

void krzyzowanie(short* tab, int nb, int na, ) {
	
}

short gen() {
	const int n = 4;
	const int m = 10;
	short* bigarr = new short [m];

	for (int i = 0; i < m; i++) {
		ch[i] = rand() % 0x20;
	}

	short* smallarr = selekcja(bigarr, m, n);

	for (int i = 0; i < 30; i++) {
		bla bla bla
	}

	return ;
}

int main() {
	srand(time(NULL));

	return 0;
}
