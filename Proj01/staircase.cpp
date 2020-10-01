/*
 * File Name: Staircase
 * Name: Daniel Lo
 * Class: ECE 150
 * Date: Oct 1 2020
 * Description: Emulates the "greatest integer less than" (gin) function
 */

#include <iostream>

int main();

int main2() {
	//Variables
	double x{};
	int stair {0};

	//Input
	std::cout << "Enter value of x: ";
	std::cin >> x;

	if (x >= 0) {
		while (x >= stair+1) {   //increment until stair+1 is greater than or equal to input
			stair++;
		}
	} else {
		while (x < stair) {	//decrement until stair is less than the input
			stair--;
		}
	}

	//Output
	std::cout << "The value of stair(x) is: ";
	std::cout << stair;
	std::cout << std::endl;

	return 0;
}
