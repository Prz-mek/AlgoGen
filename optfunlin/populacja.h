#ifndef _POPULACJA_H_
#define _POPULACJA_H_

class Populacja {
private:
	int liczebnosc;
	short* osobniki;

public:
	Populacja(int n);

	int F(int i);

	void losuj();
	
	bool selekcja(int nowa_populacja);

	void krzyzowanie(int ile_nowych, double P_k, double P_m);		// P_k - prawdopodobienstwo krzyzowania
										// P_m - prawdopodobienstwo mutacji
	short znajdz_najlepszy();
	
	~Populacja();
};

#endif
