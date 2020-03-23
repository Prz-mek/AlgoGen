#include <iostream>
#include <cstdlib>
#include <ctime>

#include "pigen.h"

int main(int argc, char** argv) {
	double maxmis = argc > 1 ? atof(*(argv + 1)) : 0.01;
	Population pop = Population(100);
	srand(time(NULL));
	int p;
	int q;
	double mis = 1000;
	
	while (mis > maxmis) {
		pop.crossover(0.7, 0.02);
		pop.selection(50);

		// Sprawdzanie błędu
		Individual b = pop.findBest();
		int bch = b.getChromosome();
		p = bch & 0xFFC00;
		p >>= 10;
		q = bch & 0x3FF;
		mis = (double)p / (double)q - PI;
		mis = mfabs(mis);
	}

	std::cout << p << " / " << q << " = " << (double)p / (double)q << std::endl;

	return 0;
}
