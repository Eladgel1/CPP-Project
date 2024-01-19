#pragma once
#include <iostream>
#include "WingedAnimal.h"
#include "Predator.h"
using namespace std;

class Eagle :virtual public WingedAnimal,Predator {
private:
	int sight_distance;
public:
	Eagle();
	Eagle(char* c, int fs, int a, float w, int ws, int food, int sd);
	Eagle(const Eagle& e);
	virtual const char* get_type()const { return "Eagle"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_flying_speed()const { return this->flying_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_wing_size()const { return this->wing_size; }
	virtual int get_amount()const { return this->amount_of_food; }
	virtual int get_sight_distance()const { return this->sight_distance; }
	virtual void set_color(char* color);
	virtual void set_flying_speed(int fly) { this->flying_speed = fly; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_wing_size(int wingsize) { this->wing_size = wingsize; }
	virtual void set_amount(int amount) { this->amount_of_food = amount; }
	virtual void set_sight_distance(int sd) { this->sight_distance = sd; }
	virtual void flying()const;
	virtual void eat()const;
	virtual void print()const;
	virtual ~Eagle();
};