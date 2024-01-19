#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "MarineAnimal.h"
#include "WingedAnimal.h"
#include "Flamingo.h"
using namespace std;

Flamingo::Flamingo():Animal(),MarineAnimal(),WingedAnimal() {}

Flamingo::Flamingo(char* c, int sw, int a, float w, int fs, int ws) :Animal(c,a,w), MarineAnimal(c, sw, a, w), WingedAnimal(c, fs, a, w, ws) {}

Flamingo::Flamingo(const Flamingo& f) :Animal(f), MarineAnimal(f), WingedAnimal(f) {}

void Flamingo::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Flamingo::swimming()const {
	cout << "Swims at a speed of about " << this->swimming_speed << " km/h" << endl;
}

void Flamingo::flying()const {
	cout << "Flies at a speed of about " << this->flying_speed << " km/h" << endl << endl;
}

void Flamingo::print()const {
	cout << "Flamingo color:" << this->color << endl
		<< "Flamingo age:" << this->age << endl
		<< "Flamingo weight:" << this->weight << endl
		<< "Flamingo wing size:" << this->wing_size << endl;
	this->swimming();
	this->flying();
}

Flamingo::~Flamingo() { delete[]this->color; }