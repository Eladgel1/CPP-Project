#pragma once
#include <iostream>
#include "Predator.h"
#include "Reptile.h"
using namespace std;

class Snake :virtual public Predator, Reptile {
public:
	Snake();
	Snake(char* c, int ls, int a, float w, int food, bool l);
	Snake(const Snake& sn);
	virtual const char* get_type()const { return "Snake"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_land_speed()const { return this->land_speed; }
	virtual int get_age()const { return this->age; }
	virtual int get_amount()const { return this->amount_of_food; }
	virtual float get_weight()const { return this->weight; }
	virtual bool get_legs_existence()const { return this->legs; }
	virtual void set_color(char* color);
	virtual void set_land_speed(int land) { this->land_speed = land; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_amount(int amount) { this->amount_of_food = amount; }
	virtual void motion()const;
	virtual void eat()const;
	virtual void print()const;
	virtual ~Snake();
};