#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
	string _name;
	string _surname;
	unsigned int _age;
public:
	Student();
	Student(string, string, int);
	void setName(string);
	void setSurname(string);
	void setAge(int);
	void show();
	string getName();
	string getSurname();
	int getAge();
	void serialize(ostream&) const;
	void deserialize(istream&);
};

