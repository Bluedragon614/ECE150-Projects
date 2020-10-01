/*
 * File Name: Income Tax
 * Name: Daniel Lo
 * Class: ECE 150
 * Date: Sep 23 2020
 * Description: Calculates the tax based off of an input as income. Based on actual income tax rates in Canada
 */

#include <iostream>

#ifndef MARMOSET_TESTING
int main();
#endif

double income_tax(double income);

double income_tax(double income) {
	//Constants
	const double TAX_RATE1{0.15};
	const double TAX_RATE2{0.205};
	const double TAX_RATE3{0.26};
	const double TAX_RATE4{0.29};
	const double TAX_RATE5{0.33};

	const double BRACKET1{47630};
	const double BRACKET2{95259};
	const double BRACKET3{147667};
	const double BRACKET4{210371};

	//Variables
	double tax{0.0};

	//Tax each income bracket from the top down
	if (income > BRACKET4) {
		tax += (income - BRACKET4)*TAX_RATE5;
		income -= (income - BRACKET4);
	}
	if (income > BRACKET3) {
		tax += (income - BRACKET3)*TAX_RATE4;
		income -= (income - BRACKET3);
	}
	if (income > BRACKET2) {
		tax += (income - BRACKET2)*TAX_RATE3;
		income -= (income - BRACKET2);
	}
	if (income > BRACKET1) {
		tax += (income - BRACKET1)*TAX_RATE2;
		income -= (income - BRACKET1);
	}
	tax += income*TAX_RATE1;

	return tax;
}

#ifndef MARMOSET_TESTING
int main(){
	//sample inputs
	const int input1{24000};
	const int input2{67000};
	const int input3{285000};

	//output
	std::cout << "$" << input1 << " will be taxed: $" << income_tax(input1) << std::endl;
	std::cout << "$" << input2 << " will be taxed: $" << income_tax(input2) << std::endl;
	std::cout << "$" << input3 << " will be taxed: $" << income_tax(input3) << std::endl;
	return 0;
}
#endif
