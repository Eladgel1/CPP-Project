#include <iostream>
#include "Animal.h"
#include "WingedAnimal.h"
using namespace std;

WingedAnimal::WingedAnimal() :Animal() {
	this->flying_speed = 0;
	this->wing_size = 0;
}

WingedAnimal::WingedAnimal(char* c, int fs, int a, float w, int ws) : Animal(c, a, w) {
	this->wing_size = ws;
	this->flying_speed = fs;
}

WingedAnimal::WingedAnimal(const WingedAnimal& wa) : Animal(wa) {
	this->wing_size = wa.wing_size;
	this->flying_speed = wa.flying_speed;
}

WingedAnimal::~WingedAnimal() { delete[]this->color; }