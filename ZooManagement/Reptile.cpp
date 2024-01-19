#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "Reptile.h"
using namespace std;

Reptile::Reptile() :Animal(),LandAnimal() {
	this->legs = false;
}

Reptile::Reptile(char* c, int ls, int a, float w, bool l) :Animal(c,a,w), LandAnimal(c, ls, a, w) {
	this->legs = l;
}

Reptile::Reptile(const Reptile& reptile) :Animal(reptile), LandAnimal(reptile) {
	this->legs = reptile.legs;
}

Reptile::~Reptile() { delete[]this->color; }