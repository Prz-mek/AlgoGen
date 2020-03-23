#include <cstdlib>

#include "pigen.h"

// ----------------------------- Individual ---------------------------------------

Individual::Individual() {
	chromosome = rand() % 0xFFFFF;		// troche nieelastyczne
}

int Individual::getChromosome() {
	return chromosome;
}

void Individual::setChromosome(int x) {
	chromosome = x & 0xFFFFF;
}

double Individual::fitness() {
	double x = chromosome & 0xFFC00;
	x /= 1024;
	x /= chromosome & 0x3FF;
	x -= PI;
	x = mfabs(x);
	x = 1000 - x;
	
	return x;
}

Individual Individual::hier(Individual partner) {	// Jeden podzial
	int length = rand() % 20;
	short mask = 1;
	for (int j = 0; j < length; j++) {
		mask *= 2;
	}
	mask--;

	Individual x;
       	setChromosome((chromosome & mask) + (partner.getChromosome() & (0xFFFFF - mask)));

	return x;
}

Individual Individual::mutation() {
	int mbit = rand() % 19;
	mbit = 1 << mbit;
	int ch = chromosome;
	if (ch & mbit)
		ch -= mbit;
	else
		ch += mbit;

	Individual x;
	x.setChromosome(ch);
	return x;
}

Individual::~Individual() {
	chromosome = 0;
}

// ---------------------------- Population ----------------------------------------

Population::Population() {
	number = 8;
	size = 8;
	ind = new Individual [size];
}

Population::Population(int n) {
	number = n;
	size = n;
	ind = new Individual [size];
}

void Population::doubleSize() {
	Individual* tmp = new Individual[size * 2];
	for (int i = 0; i < number; i++)
		tmp[i] = ind[i];

	delete [] ind;
	ind = tmp;
	size *= 2;
}

void Population::resize() {
	Individual* tmp = new Individual [number];
	for (int i = 0; i < number; i++)
		tmp[i] = ind[i];

	delete [] ind;
	ind = tmp;
	size = number;
}

void Population::add(Individual n) {
	if (size <= number)
		doubleSize();

	ind[number] = n;
	number++;
}

Individual Population::get(int index) {
	// if (index >= number)		// Nie wiem jak to poprawic
	//	return NULL;
	// else
		return ind[index];
}

void Population::selection(int n) {
	while (n < number) {
		int num = number - 1;
		for (int i = 0, j = num; i < j && n < number; i++, j--) {
			if (ind[i].fitness() < ind[j].fitness()) {
				ind[i] = ind[j];
			}
			number--;
		}
	}
	resize();
}

void Population::crossover(double P_c, double P_m) {		// Z mutacja
	int n = number;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double X = (double)rand() / RAND_MAX;
			if (X <= P_c) {
				Individual tmp = ind[i].hier(ind[j]);
				add(tmp);
				tmp = ind[j].hier(ind[i]);
				add(tmp);
			}
		}
	}
	// Teraz mutacja
	n = number;
	for (int i = 0; i < n; i++) {
		double X = (double)rand() / RAND_MAX;
		if (X <= P_m) {
			Individual tmp = ind[i].mutation();
			add(tmp);
		}
	}
	resize();
}

Individual Population::findBest() {
	Individual best = ind[0];
	for (int i = 1; i < number; i++) {
		if (ind[i].fitness() > best.fitness())
		       best = ind[i];	
	}
	return best;
}

Population::~Population() {
	delete [] ind;
}
