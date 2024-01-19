#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "LandAnimal.h"
#include "Predator.h"
#include "Lion.h"
using namespace std;

Lion::Lion() :Animal(),LandAnimal(), Predator() {
	this->roaring_power = NULL;
}

Lion::Lion(char* c, int ls, int a, float w, int food, char* rp) : Animal(c,a,w),LandAnimal(c, ls, a, w), Predator(c,a,w,food) {
	this->roaring_power = new char[strlen(rp) + 1];
	if (!this->roaring_power) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->roaring_power, rp);
}

Lion::Lion(const Lion& l) :Animal(l), LandAnimal(l), Predator(l) {
	this->roaring_power = new char[strlen(l.roaring_power) + 1];
	if (!this->roaring_power) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->roaring_power, l.roaring_power);
}

void Lion::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Lion::set_roaring_power(char* roar) {
	delete[]this->roaring_power;
	this->roaring_power = new char[strlen(roar) + 1];
	if (!this->roaring_power) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->roaring_power, roar);
}

void Lion::motion()const {
	cout << "Moving at a speed of about " << this->land_speed << " km/h" << endl << endl;
}

void Lion::eat()const {
	cout << "Eats about " << this->amount_of_food << " kg of food every day" << endl;
}

void Lion::print()const {
	cout << "Lion color:" << this->color << endl
		<< "Lion age:" << this->age << endl
		<< "Lion weight:" << this->weight << endl
		<< "Lion roaring power:" << this->roaring_power << endl;
	this->eat();
	this->motion();
}

Lion::~Lion() {
	delete[]this->color;
	delete[]this->roaring_power;
}