#include <iostream>

enum class Color
{
	Red,
	Yellow,
	Green,
	Blue
};

struct Position
{
	int x = 0;
	int y = 0;
};

// Base class
class Car
{
protected:
	Color color;
	Position position;
public:
	Car() : color(Color(1)), position{0, 0} {}

	Car(const Color color_, const Position position_) : color(color_), position(position_) {}

// function to move car
	void move(const int x_, const int y_)
	{
		position.x += x_;
		position.x += y_;
	}
};

// Derived class
class SportCar : public Car
{
private:
	int max_speed;
public:
	SportCar() : max_speed(200) {} 

	SportCar(const int max_speed_) : max_speed(max_speed_) {}

	SportCar(const Color color_, const Position position_, const int max_speed_) : 
		Car(color_, position_), max_speed(max_speed_) {}
};

// Derived class
class Truck : public Car
{
private:
	int load_capacity;
public:
	Truck() : load_capacity(200) {}

	Truck(const int max_speed_) : load_capacity(max_speed_) {}

	Truck(const Color color_, const Position position_, const int load_capacity_) :
		Car(color_, position_), load_capacity(load_capacity_) {}
};

int main()
{
	SportCar sport_car; // default Car constructor and default SportCar constructor
	Truck truck(Color(3), Position{ 5, 5 }, 1000); // Car and Truck constructor with params

	sport_car.move(1, 1);
	truck.move(2, 2);

	return 0;
}
