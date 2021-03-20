#include "myclass.hxx"


MyClass::MyClass()
    : _value(0)
{}

MyClass::~MyClass() = default;

void MyClass::value(int value)
{
	_value = value;
}

int MyClass::value() const
{
	return _value;
}
