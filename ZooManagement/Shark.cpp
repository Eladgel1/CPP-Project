#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
#include "MarineAnimal.h"
#include "Predator.h"
#include "Shark.h"
using namespace std;

Shark::Shark() :Animal(),MarineAnimal(), Predator() {
	this->fin_size = 0;
}

Shark::Shark(char* c, int sw, int a, float w, int food, int fin) :Animal(c,a,w), MarineAnimal(c, sw, a, w), Predator(c, a, w, food) {
	this->fin_size = fin;
}

Shark::Shark(const Shark& sh) :Animal(sh), MarineAnimal(sh), Predator(sh) {
	this->fin_size = sh.fin_size;
}

void Shark::set_color(char* color) {
	delete[]this->color;
	this->color = new char[strlen(color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, color);
}

void Shark::swimming()const {
	cout<<"Swims at a speed of about " << this->swimming_speed << " km/h" << endl; 
}

void Shark::eat()const {
	cout << "Eats about " << this->amount_of_food << " kg of food every day" << endl<<endl;
}

void Shark::print()const{
	cout << "Shark color:" << this->color << endl
		<< "Shark age:" << this->age << endl
		<< "Shark weight:" << this->weight << endl
		<< "Shark fin size:" << this->fin_size << endl;
	this->swimming();
	this->eat();
}

Shark::~Shark() { delete[]this->color; }