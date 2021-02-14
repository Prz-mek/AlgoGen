#include "map.hpp"

#define START_SIZE 16

// --- City methods --- //

City::City() {
	this->id = -1;
	this->x = 0;
	this->y = 0;
}

City::City(int id, double x, double y) {
	this->id = id;
	this->x = x;
	this->y = y;
}

int City::getId() {
	return id;
}

double City::getX() {
	return x;
}

double City::getY() {
	return y;
}


// --- Map methods --- //

Map::Map() {
	num = 0;
	size = START_SIZE;
	cities = new City[size];
}

void Map::add(City x) {
	if (num >= size) {
		doubleSize();
	}

	cities[num++] = x;
}

City Map::get(int i) {
	return cities[i];
}

void Map::trim() {
	City* temp = new City[num];

	for (int i = 0; i < num; i++) {
		temp[i] = cities[i];
	}

	delete [] cities;
	cities = temp;
}

void Map::doubleSize() {
	size *= 2;
	City* temp = new City[size];

	for (int i = 0; i < num; i++) {
		temp[i] = cities[i];
	}

	delete [] cities;
	cities = temp;
}

Map::~Map() {
	delete [] cities;
}


// --- Read cities from file --- //

Map readCities(char* path) {

	

	return NULL;
}
