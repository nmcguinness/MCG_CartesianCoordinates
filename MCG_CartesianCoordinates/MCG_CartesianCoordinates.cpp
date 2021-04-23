// MCG_CartesianCoordinates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

/// @brief Represent a position vector in 3D space
class Vector3 {
private:  //access modifier
	//float = 4 bytes x 3 = 12 bytes
	float x, y, z;  //fields/member variables

public: //access modifier

	//constructor - method
	Vector3(float dx, float dy, float dz) {
		x = dx;
		y = dy;
		z = dz;
	}

	Vector3(/*parameters*/) {  //default constructor
		x = 0;
		y = 0;
		z = 0;
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

	Vector3 Normalize() {
		//get the vector3 length
		float len = this->Length();

		//divide each component (x,y,z) by length
		float nx = this->x / len;
		float ny = this->y / len;
		float nz = this->z / len;

		//make a new vector3 with these values
		Vector3 norm(nx, ny, nz);

		//return this vector
		return norm;
	}

	void NormalizeOriginal() { //method overloading
		//get the vector3 length
		float len = this->Length();

		//divide each component (x,y,z) by length
		this->x = this->x / len;
		this->y = this->y / len;
		this->z = this->z / len;
	}

	float Distance(Vector3 other) {
		//subtract and square each component
		float deltaXSqrd = pow(this->x - other.getX(), 2);					//this->x - other.getX() * this->x - other.getX();
		float deltaYSqrd = pow(this->y - other.getY(), 2);
		float deltaZSqrd = pow(this->z - other.getZ(), 2);

		//sum all squares + sqrt
		float sum = sqrt(deltaXSqrd + deltaYSqrd + deltaZSqrd);

		//return result
		return sum;
	}

	string ToString() {
		return "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	}
};

int doAnotherthing(int b) {
	return b * b;
}

int doSomething(int a) {
	int x = doAnotherthing(a);
	return x;
}

int main()
{
	int result = doSomething(5);
	cout << "answer is " << result;

	Vector3 b(-2, 5, 3);  //instantiate a variable, b it is of type Vector3

	std::cout << "Vector is " << b.ToString() << std::endl;
	std::cout << "x value:" << b.getX() << std::endl;
	std::cout << "length is " << b.Length() << std::endl;

	b.setX(4);
	std::cout << "new x value:" << b.getX() << endl;
	std::cout << "new length is " << b.Length() << endl;

	Vector3 origin;
	std::cout << "(" << origin.getX() << "," << origin.getY() << "," << origin.getZ() << ")" << std::endl;

	string s = origin.ToString();
	cout << s << "\r\n"; //carriage return, new line

	Vector3 normalizedB = b.Normalize();
	cout << normalizedB.ToString() << endl;

	b.NormalizeOriginal();
	cout << b.ToString() << endl;

	Vector3 dublin(1, 2, 3);
	Vector3 dundalk(4, 5, 6);

	float distance = dundalk.Distance(dublin);
	cout << "Distance between towns is " << distance << endl;
}