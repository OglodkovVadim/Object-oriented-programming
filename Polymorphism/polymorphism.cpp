#include <iostream>

class Base
{
public:
	virtual void print()
	{
		std::cout << "\tI'm Base" << std::endl;
	}
};

class Derived : public Base
{
public:
	void print() override
	{
		std::cout << "\tI'm Derived" << std::endl;
	}
};

int main()
{

// simple override 
	std::cout << "Simple:" << std::endl;

	Base base_simple;
	Derived derived_simple;

	base_simple.print();
	derived_simple.print();

// cast derived to base
	std::cout << "Up_cast: (derived -> base)" << std::endl;

	Derived derived_upcast;
	Base* base_upcast = &derived_upcast;

	base_upcast->print();
	derived_upcast.print();

// cast base to derived
	std::cout << "Down_cast: (base -> derived)" << std::endl;

	Base* base_downcast = new Base();
	Derived* derived_downcast = static_cast<Derived*>(base_downcast);

	base_downcast->print();
	derived_downcast->print();


	return 0;
}
