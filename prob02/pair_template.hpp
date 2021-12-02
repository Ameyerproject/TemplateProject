#ifndef __PAIR_TEMPLATE_HPP__
#define __PAIR_TEMPLATE_HPP__

#include <iostream>

template <typename T>
class MyPair {
private:
	T _value1;
	T _value2;

public:
	MyPair(T value1, T value2) : _value1{ value1 }, _value2{ value2 } {}

	T getValue1()
	{
		return _value1;
	}

	T getValue2()
	{
		return _value2;
	}

	void display()
	{
		std::cout << "[" << _value1 << ", " << _value2 << "]";
	}

	void displayReverse()
	{
		std::cout << "[" << _value2 << ", " << _value1 << "]";
	}

	T maxValue() { 
		T max = _value1 > _value2 ? _value1 : _value2; 
		return max; 
	}

	T minValue() { 
		T min = _value1 < _value2 ? _value1 : _value2; 
		return min; 
	}

	void swapValue() 
	{ 
		std::swap(_value1, _value2); 
	}
};

#endif