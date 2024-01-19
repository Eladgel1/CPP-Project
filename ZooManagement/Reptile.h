#pragma once
#include <iostream>
#include "LandAnimal.h"
using namespace std;

class Reptile :virtual public LandAnimal {
protected:
	bool legs;
public:
	Reptile();
	Reptile(char* c, int ls, int a, float w, bool l);
	Reptile(const Reptile& reptile);
	virtual const char* get_type()const = 0;
	virtual char* get_color()const = 0;
	virtual int get_land_speed()const = 0;
	virtual int get_age()const = 0;
	virtual float get_weight()const = 0;
	virtual bool get_legs_existence()const = 0;
	virtual void set_color(char* color) = 0;
	virtual void set_land_speed(int land) = 0;
	virtual void set_age(int age) = 0;
	virtual void set_weight(float weight) = 0;
	virtual void motion()const = 0;
	virtual void print()const = 0;
	virtual ~Reptile();
};