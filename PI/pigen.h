#ifndef _PIGEN_H_
#define _PIGEN_H_

class Individual {
private:
	int chromosome;

public:
	Individual();

	int getChromosome();

	double fitness();

	Individual hier(Individual partner);

	Individual mutation();

	~Individual();
};

class Population {
private:
	int number;
	Indyvidual* ind;

public:
	Population(int n);

	void selection(int n);

	void crossover();

	~Population();
};

#endif
