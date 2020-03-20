#include <iostream>
#include <climits>

#include "populacja.h"

Populacja::Populacja(int n) {
	liczebnosc = n;
	osobniki = new short [n];
	for (int i = 0; i < n; i++) {
		osobniki[i] = 0;
	}
}

void Populacja::losuj() {
	for (int i = 0; i < liczebnosc; i++) {
		osobniki[i] = rand() % 32;
	}
}

int Populacja::F(int i) {
	if (i < 0 || i >= liczebnosc)
		return INT_MIN;
	return 2 * osobniki[i] + 1;
}

bool Populacja::selekcja(int nowa_liczebnosc) {
	if ( nowa_liczebnosc <= liczebnosc)
		return false;

	short* npop = new short [nowa_liczebnosc];	

	// Tworzenie ruletki
	double* ring = new double [liczebnosc];
	double sum = 0.0;
	for (int i = 0; i < liczebnosc; i++) {
		ring[i] = F(i);
		sum += ring[i];
	}
	for (int i = 0; i < liczebnosc; i++) {
		ring[i] /= sum;
		ring[i] *= 100.0;
	}

	// Losowanie
	for (int i = 0; i < nowa_liczebnosc; i++) {
		double r = 100.0 * rand() / RAND_MAX;
		double s = 0.0;
		int j = 0;
		do {
			s += ring[j];
			j++;
		} while (s <= r);

		npop[i] = osobniki[j];
	}
	
	liczebnosc = nowa_liczebnosc;
	delete [] osobniki;
	osobniki = npop;

	return true;
}

void Populacja::krzyzowanie(int ile_nowych, double P_c, double P_m) {
	int max = liczebnosc + ile_nowych;
	short* newpop = new short [max];

	for (int i = 0; i < liczebnosc; i++) {
		newpop[i] = osobniki[i];
	}

	for (int i = liczebnosc; i < max; i++) {
		int index1 = rand() % liczebnosc;
		int index2 = rand() % liczebnosc;		// moze sie powtarzac
		int podzial = rand() % 4;
		short mask = 1;
		for (int j = 0; j < podzial; j++) {
			mask *= 2;
		}
		mask--;

		// krzyzowanie
		newpop[i] = (osobniki[index1] & mask) + (osobniki[index2] & (31 - mask));

		// mutacja
		double X = (double)rand() / RAND_MAX;
		if (X <= P_m || index1 == index2) {
			short mbit = rand() % 4;
			mbit = 1 << mbit;
			if (newpop[i] & mbit)
				newpop[i] -= mbit;
			else
				newpop[i] += mbit;
		}
	}

	liczebnosc = max;
	delete [] osobniki;
	osobniki = newpop;
}

short Populacja::znajdz_najlepszy() {
	int best = 0;
	for (int i = 1; i < liczebnosc; i++) {
		if (F(best) < F(i))
			best = i;
	}
	return osobniki[best];
}

Populacja::~Populacja() {
	delete [] osobniki;
}
