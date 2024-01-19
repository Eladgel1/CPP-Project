#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "Rodent.h"
#include "Squirrel.h"
using namespace std;

Squirrel::Squirrel() :Animal(),LandAnimal(), Rodent() {
	this->nut_amount = 0;
}

Squirrel::Squirrel(char* c, int ls, int a, float w, int tl, int na) : Animal(c, a, w), LandAnimal(c, ls, a, w), Rodent(c, ls, a, w, tl) {
	this->nut_amount = na;
}

Squirrel::Squirrel(const Squirrel& sq) :Animal(sq),LandAnimal(sq), Rodent(sq) {
	this->nut_amount = sq.nut_amount;
}

void Squirrel::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Squirrel::motion()const {
	cout << "Moving at a speed of about " << this->land_speed << " km/h" << endl << endl;
}

void Squirrel::print()const {
	cout << "Squirrel color:" << this->color << endl
		<< "Squirrel age:" << this->age << endl
		<< "Squirrel weight:" << this->weight << endl
		<< "Squirrel tail length:" << this->tail_length << endl
		<< "Can carry about " << this->nut_amount << " nut/s" << endl;
	this->motion();
}

Squirrel::~Squirrel() { delete[]this->color; }