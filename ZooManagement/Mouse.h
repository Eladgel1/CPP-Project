#pragma once
#include <iostream>
#include "Rodent.h"
using namespace std;

class Mouse :virtual public Rodent {
public:
	Mouse();
	Mouse(char* c, int ls, int a, float w, int tl);
	Mouse(const Mouse& m);
	virtual const char* get_type()const { return "Mouse"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_land_speed()const { return this->land_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_tail_length()const { return this->tail_length; }
	virtual void set_color(char* color);
	virtual void set_land_speed(int land) { this->land_speed = land; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_tail_length(int tail) { this->tail_length = tail; }
	virtual void motion()const;
	virtual void print()const;
	virtual ~Mouse();
};