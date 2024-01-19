#pragma once
#include <iostream>
using namespace std;

class Animal {
protected:
	char* color;
	int age;
	float weight;
public:
	Animal();
	Animal(char* c, int a, float w);
	Animal(const Animal& a);
	virtual const char* get_type()const = 0;
	virtual char* get_color()const = 0;
	virtual int get_age()const = 0;
	virtual float get_weight()const = 0;
	virtual void set_color(char *color) = 0;
	virtual void set_age(int age) = 0;
	virtual void set_weight(float weight) = 0;
	virtual void print()const = 0;
	virtual ~Animal();
};