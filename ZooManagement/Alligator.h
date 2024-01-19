#pragma once
#include <iostream>
#include "MarineAnimal.h"
#include "Reptile.h"
using namespace std;

class Alligator :virtual public MarineAnimal, Reptile {
public:
	Alligator();
	Alligator(char* c, int sw, int a, float w, int ls, bool l);
	Alligator(const Alligator& al);
	virtual const char* get_type()const { return "Alligator"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_land_speed()const { return this->land_speed; }
	virtual int get_swimming_speed()const { return this->swimming_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual bool get_legs_existence()const { return this->legs; }
	virtual void set_color(char* color);
	virtual void set_land_speed(int land) { this->land_speed = land; }
	virtual void set_swimming_speed(int swim) { this->swimming_speed = swim; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void motion()const;
	virtual void swimming()const;
	virtual void print()const;
	virtual ~Alligator();
};