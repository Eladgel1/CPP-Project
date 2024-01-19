#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class MarineAnimal :virtual public Animal {
protected:
	int swimming_speed;
public:
	MarineAnimal();
	MarineAnimal(char* c, int sw, int a, float w);
	MarineAnimal(const MarineAnimal& ma);
	virtual const char* get_type()const = 0;
	virtual char* get_color()const = 0;
	virtual int get_swimming_speed()const = 0;
	virtual int get_age()const = 0;
	virtual float get_weight()const = 0;
	virtual void set_color(char* color) = 0;
	virtual void set_swimming_speed(int swim) = 0;
	virtual void set_age(int age) = 0;
	virtual void set_weight(float weight) = 0;
	virtual void swimming()const = 0;
	virtual void print()const = 0;
	virtual ~MarineAnimal();
};