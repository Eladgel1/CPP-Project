#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Squirrel.h"
#include "Lion.h"
#include "Snake.h"
#include "Alligator.h"
#include "Bird.h"
#include "Eagle.h"
#include "Flamingo.h"
#include "Shark.h"
#include "Mouse.h"
#include "Zoo.h"
using namespace std;

Zoo::Zoo() {
	this->data = NULL;
	this->size = 0;
}

Animal* Zoo::Init() {
	char color[20], * roaring_power;
	float weight;
	int type, choice, age, land_speed, swimming_speed, flying_speed, amount_of_food, wing_size,
		tail_length, nut_amount, sight_distance, monthly_flight_distance, fin_size;

	cout << "Select an animal you want to add:" << endl
		<< "1.Squirrel" << endl
		<< "2.Lion" << endl
		<< "3.Snake" << endl
		<< "4.Alligator" << endl
		<< "5.Bird" << endl
		<< "6.Eagle" << endl
		<< "7.Flamingo" << endl
		<< "8.Shark" << endl
		<< "9.Mouse" << endl << endl;
	while (true) {
		cin >> type;
		cout << endl;
		if (type == 1) {
			cout << "Enter Squirrel color,age,weight,land speed,tail length and the amount of nuts it can carry : " << endl << endl;
			cin >> color >> age >> weight >> land_speed >> tail_length >> nut_amount;
			cout << endl;
			Squirrel* sq = new Squirrel(color, land_speed, age, weight, tail_length, nut_amount);
			return sq;
		}

		if (type == 2) {
			cout << "Enter Lion color,age,weight,land speed and amount of food it eats each day : " << endl << endl;
			cin >> color >> age >> weight >> land_speed >> amount_of_food;
			cout << endl << "Select roaring power : " << endl << endl
				<< "1.Low" << endl
				<< "2.Mid" << endl
				<< "3.High" << endl << endl;
			cin >> choice;
			cout << endl;
			if (choice == 1) {
				roaring_power = new char[4];
				if (!roaring_power) {
					cout << "Error";
					exit(1);
				}
				strcpy(roaring_power, "Low");
				Lion* l = new Lion(color, land_speed, age, weight, amount_of_food, roaring_power);
				return l;
			}
			if (choice == 2) {
				roaring_power = new char[4];
				if (!roaring_power) {
					cout << "Error";
					exit(1);
				}
				strcpy(roaring_power, "Mid");
				Lion* l = new Lion(color, land_speed, age, weight, amount_of_food, roaring_power);
				return l;
			}
			if (choice == 3) {
				roaring_power = new char[5];
				if (!roaring_power) {
					cout << "Error";
					exit(1);
				}
				strcpy(roaring_power, "High");
				Lion* l = new Lion(color, land_speed, age, weight, amount_of_food, roaring_power);
				return l;
			}
			if (choice < 1 || choice>3) {
				cout << "invalid input,select animal again" << endl << endl;
				continue;
			}
		}
		if (type == 3) {
			cout << "Enter Snake color,age,weight,land speed and amount of food it eats each day : " << endl << endl;
			cin >> color >> age >> weight >> land_speed >> amount_of_food;
			cout << endl;
			Snake* sn = new Snake(color, land_speed, age, weight, amount_of_food, false);
			return sn;
		}
		if (type == 4) {
			cout << "Enter Alligator color,age,weight,land speed and swimming speed : " << endl << endl;
			cin >> color >> age >> weight >> land_speed >> swimming_speed;
			cout << endl;
			Alligator* al = new Alligator(color, swimming_speed, age, weight, land_speed, true);
			return al;
		}
		if (type == 5) {
			cout << "Enter Bird color,age,weight,flying speed,wing size and monthly flight distance : " << endl << endl;
			cin >> color >> age >> weight >> flying_speed >> wing_size >> monthly_flight_distance;
			cout << endl;
			Bird* b = new Bird(color, flying_speed, age, weight, wing_size, monthly_flight_distance);
			return b;
		}
		if (type == 6) {
			cout << "Enter Eagle color,age,weight,flying speed,wing size,sight distance and amount of food it eats each day : " << endl << endl;
			cin >> color >> age >> weight >> flying_speed >> wing_size >> sight_distance >> amount_of_food;
			cout << endl;
			Eagle* e = new Eagle(color, flying_speed, age, weight, wing_size, amount_of_food, sight_distance);
			return e;
		}
		if (type == 7) {
			cout << "Enter Flamingo color,age,weight,flying speed,wing size and swimming speed : " << endl << endl;
			cin >> color >> age >> weight >> flying_speed >> wing_size >> swimming_speed;
			cout << endl;
			Flamingo* f = new Flamingo(color, swimming_speed, age, weight, flying_speed, wing_size);
			return f;
		}
		if (type == 8) {
			cout << "Enter Shark color,age,weight,swimming speed,fin size and amount of food it eats each day : " << endl << endl;
			cin >> color >> age >> weight >> swimming_speed >> fin_size >> amount_of_food;
			cout << endl;
			Shark* sh = new Shark(color, swimming_speed, age, weight, amount_of_food, fin_size);
			return sh;
		}
		if (type == 9) {
			cout << "Enter Mouse color,age,weight,land speed and tail length : " << endl << endl;
			cin >> color >> age >> weight >> land_speed >> tail_length;
			cout << endl;
			Mouse* m = new Mouse(color, land_speed, age, weight, tail_length);
			return m;
		}
		if (type < 1 || type>9) {
			cout << "invalid input,select animal again" << endl << endl;
			continue;
		}
	}
}

Zoo& Zoo::operator+=(Animal* a) {
	Animal** temp;
	if (!this->data) {
		this->data = new Animal * [1];
		if (!this->data) {
			cout << "Error";
			exit(1);
		}
		data[0] = a;
		this->size++;
		return *this;
	}
	else if (this->data) {
		temp = new Animal * [this->size];
		if (!temp) {
			cout << "Error";
			exit(1);
		}
		for (int i = 0; i < this->size; i++) {
			temp[i] = this->data[i];
		}
		delete[]this->data;
		this->size++;
		this->data = new Animal * [this->size];
		if (!this->data) {
			cout << "Error";
			exit(1);
		}
		for (int i = 0; i < this->size - 1; i++) {
			this->data[i] = temp[i];
		}
		delete[]temp;
		this->data[this->size - 1] = a;
		return *this;
	}
}

Zoo& Zoo::operator-=(int index) {
	Animal** temp;
	temp = new Animal * [this->size - 1];
	if (!temp) {
		cout << "Error";
		exit(1);
	}
	for (int i = 0; i < index; i++) {
		temp[i] = this->data[i];
	}
	for (int i = index + 1; i < this->size; i++) {
		temp[i - 1] = this->data[i];
	}
	delete[]this->data;
	this->size--;
	this->data = new Animal * [this->size];
	if (!this->data) {
		cout << "Error";
		exit(1);
	}
	for (int i = 0; i < this->size; i++) {
		this->data[i] = temp[i];
	}
	delete[]temp;
	return *this;
}

void Zoo::set_by_index(int index) {

	char color[20], * roaring_power;
	float weight;
	int num, choice, age, land_speed, swimming_speed, flying_speed, amount_of_food, wing_size,
		tail_length, nut_amount, sight_distance, monthly_flight_distance, fin_size;

	if (strcmp(this->data[index]->get_type(), "Squirrel") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Land Speed" << endl
			<< "5.Tail Length" << endl
			<< "6.Nuts Amount" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new land speed:" << endl << endl;
			cin >> land_speed;
			cout << endl;
			if (dynamic_cast<Squirrel*>(this->data[index])) {
				dynamic_cast<Squirrel*>(this->data[index])->set_land_speed(land_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new tail length:" << endl << endl;
			cin >> tail_length;
			cout << endl;
			if (dynamic_cast<Squirrel*>(this->data[index])) {
				dynamic_cast<Squirrel*>(this->data[index])->set_tail_length(tail_length);
			}
		}
		if (choice == 6) {
			cout << "Enter new nuts amount:" << endl << endl;
			cin >> nut_amount;
			cout << endl;
			if (dynamic_cast<Squirrel*>(this->data[index])) {
				dynamic_cast<Squirrel*>(this->data[index])->set_nut_amount(nut_amount);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Lion") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Land Speed" << endl
			<< "5.Amount of Food" << endl
			<< "6.Roaring Power" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new land speed:" << endl << endl;
			cin >> land_speed;
			cout << endl;
			if (dynamic_cast<Lion*>(this->data[index])) {
				dynamic_cast<Lion*>(this->data[index])->set_land_speed(land_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new amount of food:" << endl << endl;
			cin >> amount_of_food;
			cout << endl;
			if (dynamic_cast<Lion*>(this->data[index])) {
				dynamic_cast<Lion*>(this->data[index])->set_amount(amount_of_food);
			}
		}
		if (choice == 6) {
			cout << "Select new roaring power:" << endl
				<< "1.Low" << endl
				<< "2.Mid" << endl
				<< "3.High" << endl;
			cin >> num;
			cout << endl;
			if (num == 1) {
				roaring_power = new char[4];
				strcpy(roaring_power, "Low");
				if (dynamic_cast<Lion*>(this->data[index])) {
					dynamic_cast<Lion*>(this->data[index])->set_roaring_power(roaring_power);
				}
			}
			if (num == 2) {
				roaring_power = new char[4];
				strcpy(roaring_power, "Mid");
				if (dynamic_cast<Lion*>(this->data[index])) {
					dynamic_cast<Lion*>(this->data[index])->set_roaring_power(roaring_power);
				}
			}
			if (num == 3) {
				roaring_power = new char[5];
				strcpy(roaring_power, "High");
				if (dynamic_cast<Lion*>(this->data[index])) {
					dynamic_cast<Lion*>(this->data[index])->set_roaring_power(roaring_power);
				}
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Snake") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Land Speed" << endl
			<< "5.Amount of Food" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new land speed:" << endl << endl;
			cin >> land_speed;
			cout << endl;
			if (dynamic_cast<Snake*>(this->data[index])) {
				dynamic_cast<Snake*>(this->data[index])->set_land_speed(land_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new amount of food:" << endl << endl;
			cin >> amount_of_food;
			cout << endl;
			if (dynamic_cast<Snake*>(this->data[index])) {
				dynamic_cast<Snake*>(this->data[index])->set_amount(amount_of_food);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Alligator") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Land Speed" << endl
			<< "5.Swimming Speed" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new land speed:" << endl << endl;
			cin >> land_speed;
			cout << endl;
			if (dynamic_cast<Alligator*>(this->data[index])) {
				dynamic_cast<Alligator*>(this->data[index])->set_land_speed(land_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new swimming speed:" << endl << endl;
			cin >> swimming_speed;
			cout << endl;
			if (dynamic_cast<Alligator*>(this->data[index])) {
				dynamic_cast<Alligator*>(this->data[index])->set_swimming_speed(swimming_speed);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Bird") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Flying Speed" << endl
			<< "5.Wing Size" << endl
			<< "6.Monthly Flight Distance" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new flying speed:" << endl << endl;
			cin >> flying_speed;
			cout << endl;
			if (dynamic_cast<Bird*>(this->data[index])) {
				dynamic_cast<Bird*>(this->data[index])->set_flying_speed(flying_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new wing size:" << endl << endl;
			cin >> wing_size;
			cout << endl;
			if (dynamic_cast<Bird*>(this->data[index])) {
				dynamic_cast<Bird*>(this->data[index])->set_wing_size(wing_size);
			}
		}
		if (choice == 6) {
			cout << "Enter new monthly flight distance:" << endl << endl;
			cin >> monthly_flight_distance;
			cout << endl;
			if (dynamic_cast<Bird*>(this->data[index])) {
				dynamic_cast<Bird*>(this->data[index])->set_monthly_distance(monthly_flight_distance);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Eagle") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Flying Speed" << endl
			<< "5.Wing Size" << endl
			<< "6.Amount of Food" << endl
			<< "7.Sight Distance" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new flying speed:" << endl << endl;
			cin >> flying_speed;
			cout << endl;
			if (dynamic_cast<Eagle*>(this->data[index])) {
				dynamic_cast<Eagle*>(this->data[index])->set_flying_speed(flying_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new wing size:" << endl << endl;
			cin >> wing_size;
			cout << endl;
			if (dynamic_cast<Eagle*>(this->data[index])) {
				dynamic_cast<Eagle*>(this->data[index])->set_wing_size(wing_size);
			}
		}
		if (choice == 6) {
			cout << "Enter new amount of food:" << endl << endl;
			cin >> amount_of_food;
			cout << endl;
			if (dynamic_cast<Eagle*>(this->data[index])) {
				dynamic_cast<Eagle*>(this->data[index])->set_amount(amount_of_food);
			}
		}
		if (choice == 7) {
			cout << "Enter new sight distance:" << endl << endl;
			cin >> sight_distance;
			cout << endl;
			if (dynamic_cast<Eagle*>(this->data[index])) {
				dynamic_cast<Eagle*>(this->data[index])->set_sight_distance(sight_distance);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Flamingo") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Swimming Speed" << endl
			<< "5.Flying Speed" << endl
			<< "6.Wing Size" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new swimming speed:" << endl << endl;
			cin >> swimming_speed;
			cout << endl;
			if (dynamic_cast<Flamingo*>(this->data[index])) {
				dynamic_cast<Flamingo*>(this->data[index])->set_swimming_speed(swimming_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new flying speed:" << endl << endl;
			cin >> flying_speed;
			cout << endl;
			if (dynamic_cast<Flamingo*>(this->data[index])) {
				dynamic_cast<Flamingo*>(this->data[index])->set_flying_speed(flying_speed);
			}
		}
		if (choice == 6) {
			cout << "Enter new wing size:" << endl << endl;
			cin >> wing_size;
			cout << endl;
			if (dynamic_cast<Flamingo*>(this->data[index])) {
				dynamic_cast<Flamingo*>(this->data[index])->set_wing_size(wing_size);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Shark") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Swimming Speed" << endl
			<< "5.Amount of Food" << endl
			<< "6.Fin Size" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new swimming speed:" << endl << endl;
			cin >> swimming_speed;
			cout << endl;
			if (dynamic_cast<Shark*>(this->data[index])) {
				dynamic_cast<Shark*>(this->data[index])->set_swimming_speed(swimming_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new amount of food:" << endl << endl;
			cin >> amount_of_food;
			cout << endl;
			if (dynamic_cast<Shark*>(this->data[index])) {
				dynamic_cast<Shark*>(this->data[index])->set_amount(amount_of_food);
			}
		}
		if (choice == 6) {
			cout << "Enter new fin size:" << endl << endl;
			cin >> fin_size;
			cout << endl;
			if (dynamic_cast<Shark*>(this->data[index])) {
				dynamic_cast<Shark*>(this->data[index])->set_fin_size(fin_size);
			}
		}
	}
	if (strcmp(this->data[index]->get_type(), "Mouse") == 0) {
		cout << "Choose element to change:" << endl
			<< "1.Color" << endl
			<< "2.Age" << endl
			<< "3.Weight" << endl
			<< "4.Land Speed" << endl
			<< "5.Tail Length" << endl << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			cout << "Enter new color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->data[index]->set_color(color);
		}
		if (choice == 2) {
			cout << "Enter new age:" << endl << endl;
			cin >> age;
			cout << endl;
			this->data[index]->set_age(age);
		}
		if (choice == 3) {
			cout << "Enter new weight:" << endl << endl;
			cin >> weight;
			cout << endl;
			this->data[index]->set_weight(weight);
		}
		if (choice == 4) {
			cout << "Enter new land speed:" << endl << endl;
			cin >> land_speed;
			cout << endl;
			if (dynamic_cast<Mouse*>(this->data[index])) {
				dynamic_cast<Mouse*>(this->data[index])->set_land_speed(land_speed);
			}
		}
		if (choice == 5) {
			cout << "Enter new tail length:" << endl << endl;
			cin >> tail_length;
			cout << endl;
			if (dynamic_cast<Mouse*>(this->data[index])) {
				dynamic_cast<Mouse*>(this->data[index])->set_tail_length(tail_length);
			}
		}
	}
}

void Zoo::print_by_index(int index)const {
	cout << "Details of animal number " << index + 1 << ":" << endl << endl;
	this->data[index]->print();
}

void Zoo::print_by_color(char* color)const {
	int count = 0;
	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->data[i]->get_color(), color) == 0) {
			this->data[i]->print();
			cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			count++;
		}
	}
	if (count < 1) {
		cout << "There are no animals in this color,try again" << endl << endl;
	}
}

void Zoo::print_all()const {
	for (int i = 0; i < this->size; i++) {
		this->data[i]->print();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
}

void Zoo::menu() {
	Animal* a;
	char color[20];
	int choice, index;
	cout << "Welcome to the zoo,choose one of the options below" << endl << endl;
	while (true) {
		cout << "1.Add Animal" << endl
			<< "2.Delete Animal" << endl
			<< "3.Change Animal element" << endl
			<< "4.Print Animal details" << endl
			<< "5.Print all Animals details" << endl
			<< "6.Print Animal/s by color" << endl
			<< "7.Quit" << endl << endl;
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			a = Init();
			*this += a;
			break;
		case 2:
			if (!this->data) {
				cout << "There are no animals at the zoo,try another action" << endl << endl;
				continue;
			}
			cout << "Select an animal index that you want to delete:" << endl << endl;
			cin >> index;
			cout << endl;
			if (index < 0 || index >= this->size) {
				cout << "Invalid index input,try again" << endl << endl;
				continue;
			}
			*this -= index;
			cout << "Animal deleted successfully!" << endl << endl;
			break;
		case 3:
			if (!this->data) {
				cout << "There are no animals at the zoo,try another action" << endl << endl;
				continue;
			}
			cout << "Select an index of an animal that you want to change one of its elements:" << endl << endl;
			cin >> index;
			cout << endl;
			if (index < 0 || index >= this->size) {
				cout << "Invalid index input,try again" << endl << endl;
				continue;
			}
			this->set_by_index(index);
			cout << "Element changed successfully!" << endl << endl;
			break;
		case 4:
			if (!this->data) {
				cout << "There are no animals at the zoo,try another action" << endl << endl;
				continue;
			}
			cout << "Select an index of an animal you would like to see its details:" << endl << endl;
			cin >> index;
			cout << endl;
			if (index < 0 || index >= this->size) {
				cout << "Invalid index input,try again" << endl << endl;
				continue;
			}
			this->print_by_index(index);
			break;
		case 5:
			if (!this->data) {
				cout << "There are no animals at the zoo,try another action" << endl << endl;
				continue;
			}
			this->print_all();
			break;
		case 6:
			if (!this->data) {
				cout << "There are no animals at the zoo,try another action" << endl << endl;
				continue;
			}
			cout << "Enter a color:" << endl << endl;
			cin >> color;
			cout << endl;
			this->print_by_color(color);
			break;
		case 7:
			cout << "GoodBye,see you next time" << endl;
			exit(1);
			break;
		default:
			cout << "Invalid choice,try again" << endl << endl;
			continue;
		}
	}
}

Zoo::~Zoo() {
	for (int i = 0; i < this->size; i++) {
		delete[]this->data[i];
	}
	delete[]this->data;
}