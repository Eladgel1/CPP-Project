#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "WingedAnimal.h"
#include "Bird.h"
using namespace std;

Bird::Bird() :Animal(),WingedAnimal() {
	this->monthly_flight_distance = 0;
}

Bird::Bird(char* c, int fs, int a, float w, int ws, int m) :Animal(c,a,w), WingedAnimal(c, fs, a, w, ws) {
	this->monthly_flight_distance = m;
}

Bird::Bird(const Bird& b) :Animal(b), WingedAnimal(b) {
	this->monthly_flight_distance = b.monthly_flight_distance;
}

void Bird::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
}

void Bird::flying()const {
	cout << "Flies at a speed of about " << this->flying_speed << " km/h" << endl << endl;
}

void Bird::print()const{
	cout << "Bird color:" << this->color << endl
		<< "Bird age:" << this->age << endl
		<< "Bird weight:" << this->weight << endl
		<< "Bird wing size:" << this->wing_size << endl
		<< "Bird monthly flight distance:" << this->monthly_flight_distance << endl;
	this->flying();
}

Bird::~Bird() { delete[]this->color; }