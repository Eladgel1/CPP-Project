#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "WingedAnimal.h"
#include "Predator.h"
#include "Eagle.h"
using namespace std;

Eagle::Eagle():Animal(),WingedAnimal(), Predator(){
	this->sight_distance = 0;
}

Eagle::Eagle(char* c, int fs, int a, float w, int ws, int food, int sd) :Animal(c,a,w), WingedAnimal(c, fs, a, w, ws), Predator(c, a, w, food) {
	this->sight_distance = sd;
}

Eagle::Eagle(const Eagle& e) :Animal(e), WingedAnimal(e), Predator(e) {
	this->sight_distance = e.sight_distance;
}

void Eagle::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Eagle::flying()const {
	cout << "Flies at a speed of about " << this->flying_speed << " km/h" << endl << endl;
}

void Eagle::eat()const {
	cout << "Eats about " << this->amount_of_food << " kg of food every day" << endl;
}

void Eagle::print()const {
	cout << "Eagle color:" << this->color << endl
		<< "Eagle age:" << this->age << endl
		<< "Eagle weight:" << this->weight << endl
		<< "Eagle wing size:" << this->wing_size << endl
		<< "Eagle sight distance:" << this->sight_distance << endl;
	this->eat();
	this->flying();
}

Eagle::~Eagle() { delete[]this->color; }