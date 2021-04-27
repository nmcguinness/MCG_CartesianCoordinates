// MCG_CartesianCoordinates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "MCG_CartesianCoordinates.h"

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

	float Dot(Vector3 other) {
		//TODO
		return -1;
	}

	float AngleBetweenInDegrees(Vector3 other) {
		//TODO
		return -1;
	}

	Vector3 Cross(Vector3 other) {
		//TODO
		return Vector3();
	}

	string ToString() {
		return "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	}
};

//used to show that we can step down and down and down into interesting methods
int doAnotherthing(int b) {
	return b * b;
}

int doSomething(int a) {
	int x = doAnotherthing(a);
	return x;
}

//the main starting point (insertion point) for our code
int main()
{
	cout << endl << "/********************** Adding breakpoints **********************/" << endl;
	int result = doSomething(5);
	cout << "answer is " << result;

	cout << endl << "/********************** Using - ToString **********************/" << endl;
	Vector3 b(-2, 5, 3);  //instantiate a variable, b it is of type Vector3
	std::cout << "Vector is " << b.ToString() << std::endl;

	cout << endl << "/********************** Using - get methods **********************/" << endl;
	std::cout << "x value:" << b.getX() << std::endl;
	std::cout << "length is " << b.Length() << std::endl;
	b.setX(4);
	std::cout << "new x value:" << b.getX() << endl;
	std::cout << "new length is " << b.Length() << endl;

	Vector3 origin;
	std::cout << "(" << origin.getX() << "," << origin.getY() << "," << origin.getZ() << ")" << std::endl;
	string s = origin.ToString();
	cout << s << "\r\n"; //carriage return, new line

	cout << endl << "/********************** Using - Normalize **********************/" << endl;
	Vector3 normalizedB = b.Normalize();
	cout << normalizedB.ToString() << endl;
	b.NormalizeOriginal();
	cout << b.ToString() << endl;

	cout << endl << "/********************** Using - Distance **********************/" << endl;
	Vector3 dublin(1, 2, 3);
	Vector3 dundalk(4, 5, 6);
	float distance = dundalk.Distance(dublin);
	cout << "Distance between towns is " << distance << endl;

	cout << endl << "/****************** Using - Distance & AngleBetweenInDegrees ******************/" << endl;
	//add code to check the dot product and angle between the Vector3 objects listed below
	Vector3 unitX(1, 0, 0);
	Vector3 unitY(0, 1, 0);
	Vector3 unitZ(0, 0, 1);
	Vector3 unitX_double(2, 0, 0);
	Vector3 unitY_triple(0, 3, 0);
	Vector3 unitZ_quad(0, 0, 4);

	//test Dot()
	cout << "Dot product x.y is " << unitX.Dot(unitY) << endl;
	cout << "Dot product y.z is " << unitY.Dot(unitZ) << endl;
	cout << "Dot product z.x is " << unitZ.Dot(unitX) << endl;
	cout << "Dot product 2x.3y is " << unitX_double.Dot(unitY_triple) << endl;

	//test AngleBetweenInDegrees()
	cout << "Angle between x and y is " << unitX.AngleBetweenInDegrees(unitY) << " degrees" << endl;
	cout << "Angle between y and z is " << unitY.AngleBetweenInDegrees(unitZ) << " degrees" << endl;
	cout << "Angle between z and x is " << unitZ.AngleBetweenInDegrees(unitX) << " degrees" << endl;
	cout << "Angle between z and z is " << unitZ.AngleBetweenInDegrees(unitZ) << " degrees" << endl;

	//add your own Vector3 objects and test the results of the Dot and AngleBetweenInDegrees methods
	//validate that all printed results are correct
}