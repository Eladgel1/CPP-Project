#pragma once
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

class Zoo {
private:
	Animal** data;
	int size;
public:
	Zoo();
	virtual Animal* Init();
	Zoo& operator+=(Animal *a);
	Zoo& operator-=(int index);
	virtual void set_by_index(int index);
	virtual void print_by_index(int index)const;
	virtual void print_by_color(char* color)const;
	virtual void print_all()const;
	virtual void menu();
	~Zoo();
};