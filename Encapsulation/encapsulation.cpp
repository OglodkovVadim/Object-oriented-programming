#include <iostream>

class Data
{
private: // access modifier
	unsigned int data1;
	unsigned int data2;
public: // access modifier
	Data() = default;

//  Getters
	unsigned int getData1() { return data1; } 
	unsigned int getData2() { return data2; }

// Setters
	void setData1(unsigned int data1) { this->data1 = data1; }
	void setData2(unsigned int data2) { this->data2 = data2; }
};

// example of incorrect class
class CarBad
{
public:
	void startEngine() {
		std::cout << "Engine start" << std::endl;
	}

	void startTransmission() {
		std::cout << "Transmission start" << std::endl;
	}
};

// example of correct class
class CarGood
{
private: // user dont have access to these fileds
	void startEngine() {
		std::cout << "Engine start" << std::endl;
	}

	void startTransmission() {
		std::cout << "Transmission start" << std::endl;
	}

public: // user uses these fields
	void start() {
		startEngine();
		startTransmission();
	}
};

int main()
{
	Data data;
// set some data in our fields
	data.setData1(2);
	data.setData2(3);

// get our fields to print
	std::cout << data.getData1() << std::endl;
	std::cout << data.getData2() << std::endl;

// we can mess up the order
	CarBad car_bad;
	car_bad.startEngine();
	car_bad.startTransmission();

// we don't need to know the order
	CarGood car_good;
	car_good.start();


	return 0;
}