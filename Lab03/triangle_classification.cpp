/*
 * File Name: Triangle Classification
 * Name: Daniel Lo
 * Class: ECE 150
 * Date: Sep 23 2020
 * Description: Classifies triangles into 1 of 5 different categories based off of side length
 */

#include <iostream>
#include <array>

#ifndef MARMOSET_TESTING
int main();
#endif

//Function Declaration
char classify_triangle(int a, int b, int c);

//Classifies the triangle into 1 of 5 categories
char classify_triangle(int a, int b, int c) {
	//Constants
	const char NOT_TRIANGLE {'N'};
	const char EQUILATERAL {'E'};
	const char RIGHT {'R'};
	const char ISOSCELES {'I'};
	const char SCALENE {'S'};
	const int NUM_SIDES = 3;

	//Variables
	char classification{};
	bool isSorted{false};

	//Take input into an array
	std::array<int, NUM_SIDES> sideLengths {a,b,c};

	//Sort the side lengths from least to greatest (Bubble Sort)
	for (int i{0}; i < NUM_SIDES && isSorted == false; i++) {
		int temp{0};
		isSorted = true;
		for (int j{0}; j < NUM_SIDES - i - 1; j++) {
			if (sideLengths[j] > sideLengths[j+1]) {
				temp = sideLengths[j];
				sideLengths[j] = sideLengths[j+1];
				sideLengths[j+1] = temp;
				isSorted = false;
			}
		}
	}

	//Re-assign Variables
	a = sideLengths[0];
	b = sideLengths[1];
	c = sideLengths[2];

	//Test for different triangle types
	if ((a + b) > c) {						//Test if side lengths can make a triangle
		if (a == b && b == c) {				//Test if all side lengths are equal
			classification = EQUILATERAL;
		} else if ((a*a + b*b) == (c*c)) {	//Test if it satisfies Pythagorean Theorem
			classification = RIGHT;
		} else if (a == b || b == c) {		//Test if at least 2 sides are equal
			classification = ISOSCELES;
		} else {							//If it's a valid triangle, default case is scalene
			classification = SCALENE;
		}
	} else {
		classification = NOT_TRIANGLE;
	}

	return classification;
}

#ifndef MARMOSET_TESTING
int main() {
	//Sample inputs
	std::array<int, 3> input1 {7, 7, 7};
	std::array<int, 3> input2 {13, 12, 5};
	std::array<int, 3> input3 {8, 8, 18};

	//Output sequence
	std::cout << "Side Lengths: " << input1[0] << ", " << input1[1] << ", " << input1[2] << std::endl;
	std::cout << "Classification: " << classify_triangle(input1[0], input1[1], input1[2]) << std::endl;

	std::cout << "Side Lengths: " << input2[0] << ", " << input2[1] << ", " << input2[2] << std::endl;
	std::cout << "Classification: " << classify_triangle(input2[0], input2[1], input2[2]) << std::endl;

	std::cout << "Side Lengths: " << input3[0] << ", " << input3[1] << ", " << input3[2] << std::endl;
	std::cout << "Classification: " << classify_triangle(input3[0], input3[1], input3[2]) << std::endl;

	return 0;
}
#endif
