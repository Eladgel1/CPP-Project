#pragma once
#include <iostream>
#include "MarineAnimal.h"
#include "WingedAnimal.h"
using namespace std;

class Flamingo :virtual public MarineAnimal, WingedAnimal {
public:
	Flamingo();
	Flamingo(char* c, int sw, int a, float w, int fs, int ws);
	Flamingo(const Flamingo& f);
	virtual const char* get_type()const { return "Flamingo"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_flying_speed()const { return this->flying_speed; }
	virtual int get_swimming_speed()const { return this->swimming_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_wing_size()const { return this->wing_size; }
	virtual void set_color(char* color);
	virtual void set_swimming_speed(int swim) { this->swimming_speed = swim; }
	virtual void set_flying_speed(int fly) { this->flying_speed = fly; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_wing_size(int wingsize) { this->wing_size = wing_size; }
	virtual void swimming()const;
	virtual void flying()const;
	virtual void print()const;
	virtual ~Flamingo();
};