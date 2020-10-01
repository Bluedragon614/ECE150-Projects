/*
 * File Name: Checksum (Project 2)
 * Name: Daniel Lo
 * Class: ECE 150
 * Date: Sep 30 2020
 * Description: Computes the checksum for an 8 digit number using the following algorithm
 * 				1.	When moving from the rightmost digit to the leftmost, but excluding the checksum digit d
 * 					a.	Multiply every other digit by two. Note that the first digit to multiply by two is the
 * 						first digit directly to the left of where the checksum digit will be.
 * 					b.	If the result of the multiplication is greater than 9, sum  the individual digits
 * 						of the doubled number, and use this as the new number for the specific digit.
 * 				2. 	Sum up all the digits excluding the checksum digit (use the value of the summed digits if
 * 					step 1b. is true in place of the original digit from the number).
 * 				3. 	Multiply the result from Step 2 by 9
 * 				4. 	Take the last digit from Step 3
 * Notable Restrictions: Only allowed to use <iostream> and <climits> libraries
 */

#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

//Function Declaration
unsigned int compute_checksum( unsigned int n );
unsigned int add_checksum( unsigned int n );
void add_checksum(unsigned int array[], std::size_t capacity );
bool verify_checksum(unsigned int n);
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );

//Global Constants
const int ERROR = UINT_MAX;
const int MAX = {99999999};
const int MIN = {0};

//Function for computing checksum
unsigned int compute_checksum ( unsigned int n) {
	//Local Variables
	std::size_t numDigits {0};
	int* digits;				//This is a dynamic/pointer array because of the limit of which libraries to use
	int checksum {0};

	//Count the number of digits in the integer
	for (int i{1}; n%i < n ; i *= 10) numDigits++;

	//Initialize array with size to match the # of digits
	digits = new int[numDigits];

	//Convert integer into a digit array
	for (std::size_t i{0} ; i < numDigits ; i++) {
		digits[i] = n%10;
		n /= 10;
	}

	//Step 1 of the Checksum algorithm
	for (std::size_t i{0} ; i < numDigits ; i += 2) {
		digits[i] *= 2;
		if (digits[i] > 9) {
			digits[i] = digits[i]%10 + 1;
		}
	}

	//Step 2 of Checksum algorithm
	for (std::size_t i{0} ; i < numDigits ; i++) {
		checksum += digits[i];
	}

	//Step 3
	checksum *= 9;
	//Step 4
	checksum %= 10;

	//Remove dynamic array from memory
	delete[]digits;

	return checksum;
}

//Adds a checksum digit to the end of the number
unsigned int add_checksum( unsigned int n ){
	if (n < MIN || n >= MAX) {
		return ERROR;
	} else {
		return (n * 10) + compute_checksum(n);
	}
}

//Adds a checksum digit to the end of a series of numbers
void add_checksum(unsigned int array[], std::size_t capacity ){
	for (std::size_t i = 0 ; i < capacity ; i++) {
		array[i] = add_checksum(array[i]);
	}
}

//Checks to see that the checksum is valid
bool verify_checksum(unsigned int n){
	if (n < MIN || n >= (MAX*10) + 9) {
		return false;
	} else {
		unsigned int checksum = n%10;
		n /= 10;

		if (checksum == compute_checksum(n)) {
			return true;
		} else {
			return false;
		}
	}

}

//removes the checksum digit from a number if it is valid
unsigned int remove_checksum( unsigned int n ) {
	if (verify_checksum(n)) {
		return n/10;
	} else {
		return ERROR;
	}
}

//removes the checksum digits from a series of numbers if they are valid
void remove_checksum( unsigned int array[], std::size_t capacity ) {
	for (std::size_t i = 0 ; i < capacity ; i++) {
		array[i] = remove_checksum(array[i]);
	}
}

#ifndef MARMOSET_TESTING
int main() {
	//Test individual checksum

	unsigned int value_to_protect{769518};
	unsigned int protected_value = add_checksum(value_to_protect);

	std::cout << "The value " << value_to_protect  << " with the checksum added is "
			<< protected_value << "." << std::endl;

	//Test the verification of the checksum
	if (verify_checksum(protected_value)) {
		std::cout << "The checksum is valid." << std::endl;
	}

	else   {
		std::cout << "The checksum is invalid." << std::endl;
	}

	//Test a checksum of an array of numbers
	std::size_t qty_values {3};
	unsigned int value_series[qty_values] {20201122, 20209913, 20224012};

	add_checksum(value_series, qty_values);
	std::cout << "Series with checksums added: ";

	for (std::size_t series_index {0}; series_index < qty_values; series_index++){
		std::cout << value_series[series_index] << " ";
	}
	std::cout << std::endl;

	return 0;
}
#endif
