#include <iostream>
#include <ctime>

#include "populacja.h"

int main() {
	srand(time(NULL));

	const int n = 4;
	const int m = 6;

	Populacja pop(n);
	pop.losuj();
	
	int result;

	for (int i = 0; i < 50; i++) {
		pop.selekcja(n);
		pop.krzyzowanie(m, 1.0, 0.03);

		result = pop.znajdz_najlepszy();
	}

	result = pop.znajdz_najlepszy();
	std::cout << "Najlepszy rezultat: " << result << std::endl;

	return 0;
}
