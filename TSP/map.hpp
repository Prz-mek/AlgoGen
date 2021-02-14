#ifndef	__MAP_H__
#define __MAP_H__

class City {
	private:
		int id;
		double x;
		double y;
	public:
		City();
		City(int id, double x, double y);
		int getId();
		double getX();
		double getY();
};

class Map {
	private:
		int num;
		int size;
		City* cities;
	public:
		Map();
		void add(City x);
		City get(int i);
		void trim();
		~Map();
	private:
		void doubleSize();
};

#endif
