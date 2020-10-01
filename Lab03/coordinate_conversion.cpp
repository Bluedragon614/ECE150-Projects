/*
 * File Name: Coordinate Conversion
 * Name: Daniel Lo
 * Class: ECE 150
 * Date: Sep 23 2020
 * Description: Calculates the polar coordinates of a point based on its Cartesian coordinates
 */

#include <iostream>
#include <cmath>

#ifndef MARMOSET_TESTING
int main();
#endif

//Function Declaration
double polar_radius(double x, double y);
double polar_angle(double x, double y);
void print_polar(double x, double y);

//Finds the radius of the polar coordinate
double polar_radius(double x, double y) {
	return sqrt(x*x + y*y); 				//Pythagorean Theorem
}

//Finds the angle of the polar coordinate (in degrees)
double polar_angle(double x, double y) {
	//Variables
	double alpha{atan(y/x)};
	double theta{};

	//Convert alpha into an angle over 0 <= theta <= 2pi
	if (x < 0) {
		theta = M_PI + alpha;
	} else if (y < 0) {
		theta = (2*M_PI) + alpha;
	} else {
		theta = alpha;
	}

	//Convert theta to degrees
	return theta * (180/M_PI);
}

//Print out the polar coordinates
void print_polar(double x, double y) {
	std::cout << "(" << x << "," << y << ") in polar form is: (" << polar_radius(x,y) << "," << polar_angle(x,y) << ")" << std::endl;
}

#ifndef MARMOSET_TESTING
int main() {
	//Function calls with sample inputs
	print_polar(2,2);
	print_polar(-0.5,sqrt(3)/2);
	print_polar(-2,-2*sqrt(3));
	print_polar(1,-sqrt(3));
	print_polar(0,1);

	return 0;
}
#endif
