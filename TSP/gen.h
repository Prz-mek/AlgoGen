#ifndef _PIGEN_H_
#define _PIGEN_H_


const double PI = 3.14159265358979323846;

inline double mfabs(double x) {		// Nie wiem czy nie za dluga
	if(x < 0.0)
		return -x;
	else
		return x;
}

// -------------------------------- Classes ------------------------------------

class Individual {
private:
	int chromosome;

public:
	Individual();

	int getChromosome();

	void setChromosome(int x);		// Chyba w C++ jest jakis sposob na ustawianie operatorow.

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

	void add(Individual n);

	Individual get(int index);

	void selectionT(int n);

	void selectionR(int n);

	void crossover(double P_c, double P_m);

	Individual findBest();

	~Population();
};

#endif
