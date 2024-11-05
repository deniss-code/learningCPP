#include <iostream>


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
};


int main() {
	Calculator calc;
	char choice;
	double num1, num2, result = 0;
	std::cout << "Choose your calculation method\n";
	std::cout << "+ | - | * | / \n";
	std::cin >> choice;
	
	std::cout << "Enter your numbers\n";
	std::cin >> num1 >> num2;
	switch (choice) {
	case '+':
		result = calc.add(num1, num2);
		break;
	case '-':
		result = calc.minus(num1, num2);
		break;
	case '*':
		result = calc.multiplication(num1, num2);
		break;
	case '/':
		result = calc.subtraction(num1, num2);
		break;
	default:
		std::cout << "Wrong input!\n";
	}

	std::cout << "The result is " << result;

}