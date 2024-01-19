#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "MarineAnimal.h"
#include "Reptile.h"
#include "Alligator.h"
using namespace std;

Alligator::Alligator() :Animal(),LandAnimal(),MarineAnimal(), Reptile() {}

Alligator::Alligator(char* c, int sw, int a, float w, int ls, bool l) :Animal(c,a,w),LandAnimal(c,ls,a,w), MarineAnimal(c, sw, a, w), Reptile(c, ls, a, w, l) {}

Alligator::Alligator(const Alligator& al) : Animal(al),LandAnimal(al),MarineAnimal(al), Reptile(al) {}

void Alligator::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Alligator::motion()const {
	cout << "Crawls at a speed of about " << this->land_speed << " km/h" << endl << endl;
}

void Alligator::swimming()const {
	cout << "Swims at a speed of about " << this->swimming_speed << " km/h" << endl;
}

void Alligator::print()const {
	cout << "Alligator color:" << this->color << endl
		<< "Alligaotr age:" << this->age << endl
		<< "Alligator weight:" << this->weight << endl
		<< "This reptile has 4 legs" << endl;
	this->swimming();
	this->motion();
}

Alligator::~Alligator() { delete[]this->color; }