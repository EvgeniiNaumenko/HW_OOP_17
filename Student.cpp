#include "Student.h"

Student::Student() :_name("NoName"), _surname("NOSurname"), _age(0) {}

Student::Student(string name, string surname, int age) :_name(name), _surname(surname)
{
	if (age>=0)
	{
		_age = age;
	}
	else
		throw IncorrectValueException("Incorrect value exception");
}

void Student::setName(string name)
{
	_name = name;
}

void Student::setSurname(string surname)
{
	_surname = surname;
}

void Student::setAge(int age)
{
	try
	{
		_age = age;
	}
	catch (const std::exception&)
	{

	}
}

void Student::show()
{
	cout << "Name: " << _name << endl;
	cout << "Surame: " << _surname << endl;
	cout << "Age: " << _age << endl;

}

string Student::getName()
{
	return _name;
}

string Student::getSurname()
{
	return _surname;
}

int Student::getAge()
{
	return _age;
}

void Student::serialize(ostream& os) const
{
	size_t name_length = _name.size();
	os.write(reinterpret_cast<const char*>(&name_length), sizeof(name_length));
	os.write(_name.c_str(), name_length);
	size_t surname_length = _surname.size();
	os.write(reinterpret_cast<const char*>(&surname_length), sizeof(surname_length));
	os.write(_surname.c_str(), surname_length);
	os.write(reinterpret_cast<const char*>(&_age), sizeof(_age));
}

void Student::deserialize(istream& is)
{
	size_t name_length;
	is.read(reinterpret_cast<char*>(&name_length), sizeof(name_length));
	char* buffer = new char[name_length + 1];
	is.read(buffer, name_length);
	buffer[name_length] = '\0';
	const_cast<string&>(_name) = string(buffer);
	delete[] buffer;

	size_t surname_length;
	is.read(reinterpret_cast<char*>(&surname_length), sizeof(surname_length));
	buffer = new char[surname_length + 1];
	is.read(buffer, surname_length);
	buffer[surname_length] = '\0';
	const_cast<string&>(_surname) = string(buffer);
	delete[] buffer;

	is.read(reinterpret_cast<char*>(&_age), sizeof(_age));
}
