#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;

class Predator :virtual public Animal {
protected:
	int amount_of_food;
public:
	Predator();
	Predator(char* c, int a, float w,int food);
	Predator(const Predator& p);
	virtual const char* get_type()const = 0;
	virtual char* get_color()const = 0;
	virtual int get_age()const = 0;
	virtual int get_amount()const = 0;
	virtual float get_weight()const = 0;
	virtual void set_color(char* color) = 0;
	virtual void set_age(int age) = 0;
	virtual void set_weight(float weight) = 0;
	virtual void set_amount(int amount) = 0;
	virtual void eat()const = 0;
	virtual void print()const = 0;
	virtual ~Predator();
};