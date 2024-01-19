#include <iostream>
#include "Animal.h"
#include "MarineAnimal.h"
using namespace std;

MarineAnimal::MarineAnimal() :Animal() {
	this->swimming_speed = 0;
}

MarineAnimal::MarineAnimal(char* c, int sw, int a, float w) : Animal(c, a, w) {
	this->swimming_speed = sw;
}

MarineAnimal::MarineAnimal(const MarineAnimal& ma) : Animal(ma) {
	this->swimming_speed = ma.swimming_speed;
}

MarineAnimal::~MarineAnimal() { delete[]this->color; }