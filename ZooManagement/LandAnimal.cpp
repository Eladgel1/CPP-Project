#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
using namespace std;

LandAnimal::LandAnimal() :Animal() {
	this->land_speed = 0;
}

LandAnimal::LandAnimal(char* c, int ls, int a, float w) : Animal(c, a, w) {
	this->land_speed = ls;
}

LandAnimal::LandAnimal(const LandAnimal& la) : Animal(la) {
	this->land_speed = la.land_speed;
}

LandAnimal::~LandAnimal() { delete[]this->color; }