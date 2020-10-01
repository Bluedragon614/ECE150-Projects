/*
 * File Name: List Primes
 * Name: Daniel Lo
 * Class: ECE 150
 * Date: Sep 28 2020
 * Description: Outputs all the prime numbers in a given range
 */

#include <iostream>

int main();

int main() {
	//Constants
	const std::string NO_PRIMES {"No primes in range."};

	//Variables
	int lower{};
	int upper{};
	bool isPrime {true};
	bool primesInRange {false};

	//input sequence
	std::cout << "List Primes Program" << std::endl;
	std::cout << "Enter first number: ";
	std::cin >> lower;
	std::cout << "Enter second number: ";
	std::cin >> upper;

	//output line
	std::cout << "Primes in range: ";

	//loop through range of inputs
	for (int i{lower} ; i <= upper ; i++) {

		//check if int is greater than 1
		if (i <= 1) {
			isPrime = false; 	//if 1 or less, number is not prime
		} else {
			isPrime = true; 	//assume any int greater than 1 is prime until proven not

			//loop through every int from 2 to num/2 and check if it is divisible
			for (int j{2} ; j <= i/2 ; j++) {
				if (i % j == 0) {
					isPrime = false;
				}
			}
		}

		//print if it is prime
		if (isPrime) {
			std::cout << i << " ";
			primesInRange = true;
		}
	}

	//Tell user if there are no primes in the range
	if (!primesInRange) {
		std::cout << NO_PRIMES << std::endl;
	}

	return 0;
};
