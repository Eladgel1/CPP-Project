#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "Rodent.h"
using namespace std;

Rodent::Rodent() :Animal(),LandAnimal() {
	this->tail_length = 0;
}

Rodent::Rodent(char* c, int ls, int a, float w, int tl) :Animal(c,a,w), LandAnimal(c, ls, a, w) {
	this->tail_length = tl;
}

Rodent::Rodent(const Rodent& rodent) :Animal(rodent), LandAnimal(rodent) {
	this->tail_length = rodent.tail_length;
}

Rodent::~Rodent() { delete[]this->color; }