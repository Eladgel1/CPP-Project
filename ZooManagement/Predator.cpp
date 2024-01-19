#include <iostream>
#include "Animal.h"
#include "Predator.h"
using namespace std;

Predator::Predator() :Animal() {
	this->amount_of_food = 0;
}

Predator::Predator(char* c, int a, float w, int food) : Animal(c, a, w) {
	this->amount_of_food = food;
}

Predator::Predator(const Predator& p) : Animal(p) {
	this->amount_of_food = p.amount_of_food;
}

Predator::~Predator() { delete[]this->color; }