#ifndef _SGEN_H_
#define _SGEN_H_

#include "graph.h"

// -------------------------------- Classes ------------------------------------

class Individual {
private:
	Graph graph;
	int* chromosome;

public:
	Individual(Graph g);

	int getSize();

	int* getChromosome();

	void setChromosome(int* x);

	double fitness();

	Individual hier(Individual partner);

	Individual mutation();

	~Individual();
};


class Population {
private:
	int number;
	int size;
	Individual* ind;

	void doubleSize();
	void resize();

public:
	Population();

	Population(int n);

	int getSize();

	void add(Individual n);

	Individual get(int index);

	void selectionT(int n);

	void selectionR(int n);

	void crossover(double P_c, double P_m);

	Individual findBest();

	~Population();
};

// ------------------------------------ Optimization method ---------------------------------------------



#endif
