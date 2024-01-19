#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "Rodent.h"
#include "Mouse.h"
using namespace std;

Mouse::Mouse() :Animal(), LandAnimal(), Rodent() {}

Mouse::Mouse(char* c, int ls, int a, float w, int tl) : Animal(c, a, w), LandAnimal(c, ls, a, w), Rodent(c, ls, a, w, tl) {}

Mouse::Mouse(const Mouse& m) :Animal(m),LandAnimal(m), Rodent(m) {}

void Mouse::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Mouse::motion()const {
	cout << "Moving at a speed of about " << this->land_speed << " km/h" << endl << endl;
}

void Mouse::print()const {
	cout << "Mouse color:" << this->color << endl
		<< "Mouse age:" << this->age << endl
		<< "Mouse weight:" << this->weight << endl
		<< "Mouse tail length:" << this->tail_length << endl;
	this->motion();
}

Mouse::~Mouse() { delete[]this->color; }