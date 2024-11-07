#include <iostream>
#include <math.h>
# define M_PI	3.14159265358979323846  /* pi */


class Errors {
public:
	void nullNumber() {
		std::cout << "Doing this calculation through 0 does not work!\n";
	}
};

class Calculator {
public:
	double add(double a, double b) {
		return a + b;
	}
	double minus(double a, double b) {
		return a - b;
	}
	double multiplication(double a, double b) {
		return a * b;
	}
	double subtraction(double a, double b) {
		return a / b;
	}
	double modulo(double a, double b) {
		return std::fmod(a, b);
	}
	double sin(long double angle) {
		return std::sin(angle);  // Use std::sin to avoid recursion
	}
	double cos(long double angle) {
		return std::cos(angle * M_PI / 180);  // Use std::cos
	}
	double tan(double angle) {
		return std::tan(angle * M_PI / 180);  // Use std::tan
	}
};


int main() {
	Calculator calc;
	std::string choice;
	double num1 = 0, num2 = 0, angleNum, result = 0;
	std::cout << "Choose your calculation method\n";
	std::cout << "1. Arithmetic: + | - | * | / \n";
	std::cout << "2. Trigonometric: sin | cos | tan \n";
	std::cin >> choice;
	
	if (choice == "sin" || choice == "cos" || choice == "tan") {
		std::cout << "Enter your number:\n";
		std::cin >> angleNum;
	}
	else if (choice == "+" || choice == "-" || choice == "*" || choice == "/") {
		std::cout << "Enter your numbers\nFirst Number: ";
		std::cin >> num1;
		std::cout << "Second Number: ";
		std::cin >> num2;
	}
	else {
		std::cout << "Wrong input!";
		return 0;
	}


	if (choice == "+") {
		result = calc.add(num1, num2);
	}
	else if (choice == "-") {
		result = calc.minus(num1, num2);
	}
	else if (choice == "*") {
		result = calc.multiplication(num1, num2);
	}
	else if (choice == "/") {
		result = calc.subtraction(num1, num2);
	}
	else if (choice == "sin") {
		result = calc.sin(num1);
	}
	else if (choice == "cos") {
		result = calc.cos(num1);
	}
	else if (choice == "tan") {
		result = calc.tan(num1);
	}
	else{
		std::cout << "Wrong input!\n";
	}


	std::cout << "The result is " << result;

}