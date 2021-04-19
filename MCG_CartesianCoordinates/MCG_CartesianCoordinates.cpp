// MCG_CartesianCoordinates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

/// @brief Represent a position vector in 3D space
class Vector3 {
private:  //access modifier
	float x, y, z;  //fields/member variables

public: //access modifier

	//constructor - method
	Vector3(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getZ() {
		return z;
	}

	void setX(float newValue) {
		x = newValue;
	}

	float Length() {
		float len = sqrt(x * x + y * y + pow(z, 2));
		return len;
	}

	std::string ToString() {
		return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
	}
};

int main()
{
	Vector3 b(-2, 5, 3);  //instantiate a variable, b it is of type Vector3

	std::cout << "Vector is " << b.ToString() << std::endl;
	std::cout << "x value:" << b.getX() << std::endl;
	std::cout << "length is " << b.Length() << std::endl;

	b.setX(4);
	std::cout << "new x value:" << b.getX() << std::endl;
	std::cout << "new length is " << b.Length() << std::endl;
}