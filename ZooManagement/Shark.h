#pragma once
#include <iostream>
#include "MarineAnimal.h"
#include "Predator.h"
using namespace std;

class Shark :virtual public MarineAnimal, Predator {
private:
	int fin_size;
public:
	Shark();
	Shark(char* c, int sw, int a, float w,int food,int fin);
	Shark(const Shark& sh);
	virtual const char* get_type()const { return "Shark"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_swimming_speed()const { return this->swimming_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_amount()const { return this->amount_of_food; }
	virtual int get_fin_size()const { return this->fin_size; }
	virtual void set_color(char* color);
	virtual void set_swimming_speed(int swim) { this->swimming_speed = swim; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_amount(int amount) { this->amount_of_food = amount; }
	virtual void set_fin_size(int fin) { this->fin_size = fin; }
	virtual void swimming()const;
	virtual void eat()const;
	virtual void print()const;
	virtual ~Shark();
};