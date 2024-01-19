#pragma once
#include <iostream>
#include "WingedAnimal.h"
using namespace std;

class Bird :virtual public WingedAnimal {
private:
	int monthly_flight_distance;
public:
	Bird();
	Bird(char* c, int fs, int a, float w, int ws,int m);
	Bird(const Bird& b);
	virtual const char* get_type()const { return "Bird"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_flying_speed()const { return this->flying_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_wing_size()const { return this->wing_size; }
	virtual int get_monthly_distance()const { return this->monthly_flight_distance; }
	virtual void set_color(char* color);
	virtual void set_flying_speed(int fly) { this->flying_speed = fly; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_wing_size(int wingsize) { this->wing_size = wingsize; }
	virtual void set_monthly_distance(int distance) { this->monthly_flight_distance = distance; }
	virtual void flying()const;
	virtual void print()const;
	virtual ~Bird();
};