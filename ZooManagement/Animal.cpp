#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal() {
	this->color = NULL;
	this->age = 0;
	this->weight = 0;
}

Animal::Animal(char* c, int a, float w) {
	this->color = new char[strlen(c) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	strcpy(this->color, c);
	this->age = a;
	this->weight = w;
}

Animal::Animal(const Animal& a) {
	this->color = new char[strlen(a.color) + 1];
	if (!this->color) {
		cout << "Error";
		exit(1);
	}
	this->age = a.age;
	this->weight = a.weight;
}

Animal::~Animal() { delete[]this->color; }