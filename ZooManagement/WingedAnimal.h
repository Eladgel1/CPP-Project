#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class WingedAnimal :virtual public Animal {
protected:
	int flying_speed,wing_size;
public:
	WingedAnimal();
	WingedAnimal(char* c, int fs, int a, float w,int ws);
	WingedAnimal(const WingedAnimal& wa);
	virtual const char* get_type()const = 0;
	virtual char* get_color()const = 0;
	virtual int get_flying_speed()const = 0;
	virtual int get_age()const = 0;
	virtual float get_weight()const = 0;
	virtual int get_wing_size()const = 0;
	virtual void set_color(char* color) = 0;
	virtual void set_flying_speed(int fly) = 0;
	virtual void set_age(int age) = 0;
	virtual void set_weight(float weight) = 0;
	virtual void set_wing_size(int wingsize) = 0;
	virtual void flying()const = 0;
	virtual void print()const = 0;
	virtual ~WingedAnimal();
};