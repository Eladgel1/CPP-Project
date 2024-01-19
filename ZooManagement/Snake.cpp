#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "Predator.h"
#include "Reptile.h"
#include "Snake.h"
using namespace std;

Snake::Snake() :Animal(),LandAnimal(), Predator(), Reptile() {}

Snake::Snake(char* c, int ls, int a, float w, int food, bool l) :Animal(c,a,w),LandAnimal(c,ls,a,w), Predator(c, a, w, food), Reptile(c, ls, a, w, l) {}

Snake::Snake(const Snake& sn) :Animal(sn),LandAnimal(sn), Predator(sn), Reptile(sn) {}

void Snake::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Snake::motion()const {
	cout << "Crawls at a speed of about " << this->land_speed << " km/h" << endl << endl;
}

void Snake::eat()const {
	cout << "Eats about " << this->amount_of_food << " kg of food every day" << endl;
}

void Snake::print()const {
	cout << "Snake color:" << this->color << endl
		<< "Snake age:" << this->age << endl
		<< "Snake weight:" << this->weight << endl
		<< "This reptile has no legs" << endl;
	this->eat();
	this->motion();
}

Snake::~Snake() { delete[]this->color; }