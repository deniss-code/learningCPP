#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <fstream>



int main() {
	// Declaration
	int amountOfGrades;
	int sum = 0;
	int option;

	system("cls");
	std::cout << "Do you want to name the grades or not?\n1. Yes\n2. No\n";
	std::cin >> option;

	// Check for invalid input
	if (option != 1 && option != 2) {
		std::cout << "Invalid option. Exiting program.\n";
		return 1;
	}
	system("cls");

	std::cout << "Amount of grades: ", std::cin >> amountOfGrades;
	system("cls");

	// Enter name of grades
	std::vector<int> gradeArray(amountOfGrades);
	std::vector<std::string> gradeNamesArray(amountOfGrades);
	if (option == 1) {
		

		for (int i = 0; i < amountOfGrades; ++i) {
			std::cout << "Enter the name for Grade " << i + 1 << ": " << std::endl;
			std::cin >> gradeNamesArray[i];
			std::cout << std::endl;
		}
	}
	system("cls");
	// Enter Grades
	for (int i = 0; i < amountOfGrades; ++i) {
		if (option == 1) {
			std::cout << "Enter Grade for " << gradeNamesArray[i] << ": ";
		}
		else {
			std::cout << "Enter Grade " << i + 1 << ": ";
		}
		std::cin >> gradeArray[i];
		sum += gradeArray[i];
	}
	system("cls");
	// Show grades
	std::cout << "Here are all your Grades:" << std::endl;
	for (int i = 0; i < amountOfGrades; ++i) {
		std::cout << i + 1 << ". " << gradeNamesArray[i] << ": ";
		std::cout << gradeArray[i] << std::endl;
	}
	std::cout << std::endl;

	// Ask for grade change
	std::cout << "Do you want to change any Grades?\n1. Yes \n2. No\n";
	std::cin >> option;
	system("cls");

	// Check for invalid input
	if (option != 1 && option != 2) {
		std::cout << "Invalid option. Exiting program.\n";
		return 1;
	}

	// Change grade
	while (option == 1) {
		// Show Grades
		std::cout << "Here are all your Grades:" << std::endl;
		for (int i = 0; i < amountOfGrades; ++i) {
			std::cout << i + 1 << ". " << gradeNamesArray[i] << ": ";
			std::cout << gradeArray[i] << std::endl;
		}
		std::cout << std::endl;

		
		int position;
		std::cout << "What Grade do you want to change?" << std::endl;
		std::cin >> position;
		std::cout << std::endl;
		system("cls");


		int newGrade;
		std::cout << "Enter the new Grade for " << gradeNamesArray[position - 1] << "(" << gradeArray[position - 1] << ")" << ": ";
		std::cin >> newGrade;
		sum -= gradeArray[position - 1];
		gradeArray[position - 1] = newGrade;
		sum += gradeArray[position - 1];
		std::cout << std::endl;
		system("cls");

		std::cout << "Here are your Grades:" << std::endl;
		for (int i = 0; i < amountOfGrades; ++i) {
			std::cout << i + 1 << ". " << gradeNamesArray[i] << ": ";
			std::cout << gradeArray[i] << std::endl;
		}
		std::cout << std::endl;


		std::cout << "Do you want to change another Grade? \n1. Yes \n2. No\n" << std::endl;
		std::cin >> option;
		std::cout << std::endl << std::endl;
		system("cls");
	}


	// Output result
	double avgGrade = static_cast<double>(sum) / amountOfGrades;
	std::cout << "The Average of all Grades is: " << std::fixed << std::setprecision(2) << avgGrade << std::endl;

	std::ofstream resultFile;

	resultFile.open("C:/Users/cluni/Downloads/results.txt");
	for (int i = 0; i < amountOfGrades; ++i) {
		resultFile << i + 1 << ". " << gradeNamesArray[i] << ": " << gradeArray[i] << "\n";
	}
	resultFile << "The average of all Grades is: " << std::fixed << std::setprecision(2) << avgGrade;
	resultFile.close();
	return 0;
}


