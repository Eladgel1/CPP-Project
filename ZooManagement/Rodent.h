#pragma once
#include <iostream>
#include "LandAnimal.h"
using namespace std;

class Rodent :virtual public LandAnimal {
protected:
	int tail_length;
public:
	Rodent();
	Rodent(char* c, int ls, int a, float w,int tl);
	Rodent(const Rodent& rodent);
	virtual const char* get_type()const = 0;
	virtual char* get_color()const = 0;
	virtual int get_land_speed()const = 0;
	virtual int get_age()const = 0;
	virtual float get_weight()const = 0;
	virtual int get_tail_length()const = 0;
	virtual void set_color(char* color) = 0;
	virtual void set_land_speed(int land) = 0;
	virtual void set_age(int age) = 0;
	virtual void set_weight(float weight) = 0;
	virtual void set_tail_length(int tail) = 0;
	virtual void motion()const = 0;
	virtual void print()const = 0;
	virtual ~Rodent();
};