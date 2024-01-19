#pragma once
#include <iostream>
#include "LandAnimal.h"
#include "Predator.h"
using namespace std;

class Lion :virtual public LandAnimal, Predator {
	char* roaring_power;
public:
	Lion();
	Lion(char* c, int ls, int a, float w,int food,char *rp);
	Lion(const Lion& l);
	virtual const char* get_type()const { return "Lion"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_land_speed()const { return this->land_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_amount()const { return this->amount_of_food; }
	virtual char* get_roaring_power()const { return this->roaring_power; }
	virtual void set_color(char* color);
	virtual void set_land_speed(int land) { this->land_speed = land; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_amount(int amount) { this->amount_of_food = amount; }
	virtual void set_roaring_power(char* roar);
	virtual void motion()const;
	virtual void eat()const;
	virtual void print()const;
	virtual ~Lion();
};