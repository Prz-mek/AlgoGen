#include "pigen.h"

inline double mfabs(double x) {		// Nie wiem czy nie za dluga
	if(x < 0.0)
		return -x;
	else
		return x;
}

const double PI = 3.14159265358979323846;

// ----------------------------- Individual ---------------------------------------

Individual::Individual() {
	chromosome = rand() % 0xFFFFF;		// troche nieelastyczne
}

int Individual::getChromosome() {
	return chromosome;
}

double Individual::fitness() {
	double x = chromosome & 0xFFC00;
	x /= chromosome & 0x3FF;
	x -= PI;
	x = mfabs(x);
	
	return x;
}

Individual Individual::hier(Individual partner) {	// Jeden podzial
	int length = rand() % 20;
	short mask = 1;
	for (int j = 0; j < podzial; j++) {
		mask *= 2;
	}
	mask--;

	Individual x = (chromosome & mask) + (parnter.getChromosome() & (0xFFFFF - mask));

	return x;
}

Individual Individual::mutation() {
	int mbit = rand() % 19;
	mbit = 1 << mbit;
	if (chromosome & mbit)
		newpop[i] -= mbit;
	else
		newpop[i] += mbit;
	}
}

Individual::~Individual() {
	chromosome = 0;
}

// ---------------------------- Population ----------------------------------------

Population::Population(int n) {
	number = n;
	ind = new Individual [n];
}

void Population::selsction(int n) {
	if (2 * n > number)
		return;

	int grups_size = liczebnosc / (n - 1);
	

}

Population::~Population() {
	delete [] ind;
}
