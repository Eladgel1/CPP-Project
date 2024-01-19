#pragma once
#include <iostream>
#include "Rodent.h"
using namespace std;

class Squirrel :virtual public Rodent {
private:
	int nut_amount;
public:
	Squirrel();
	Squirrel(char* c, int ls, int a, float w, int tl,int na);
	Squirrel(const Squirrel& sq);
	virtual const char* get_type()const { return "Squirrel"; }
	virtual char* get_color()const { return this->color; }
	virtual int get_land_speed()const { return this->land_speed; }
	virtual int get_age()const { return this->age; }
	virtual float get_weight()const { return this->weight; }
	virtual int get_tail_length()const { return this->tail_length; }
	virtual int get_nut_amount()const { return this->nut_amount; }
	virtual void set_color(char* color);
	virtual void set_land_speed(int land) { this->land_speed = land; }
	virtual void set_age(int age) { this->age = age; }
	virtual void set_weight(float weight) { this->weight = weight; }
	virtual void set_tail_length(int tail) { this->tail_length = tail; }
	virtual void set_nut_amount(int nut) { this->nut_amount = nut; }
	virtual void motion()const;
	virtual void print()const;
	virtual ~Squirrel();
};