#include <iostream>
#include <random>
#include <fstream>


int main() {
    // Clear console and declaration
    system("cls");
    int rangeMax;
    int option = 0;
    int input;

    // Loop for the game
    do {
        // Asking for input for the range
        std::cout << "Till what number do you wanna guess?\n";
        std::cin >> rangeMax;
        system("cls");

        // Generating the number

        std::random_device seed;
        std::default_random_engine e1(seed());
        std::uniform_int_distribution<int> uniform_dist(1, rangeMax);
        int rightNumber = uniform_dist(e1);
        std::cout << "Guess the number between 1 and " << rangeMax << "\n";
        
        // Loop for the guessing
        do {
            std::cout << std::endl;
            std::cin >> input;
            if (input > rightNumber) {
                std::cout << "You have to guess lower";
            }
            else if (input < rightNumber) {
                std::cout << "You have to guess higher";
            }
            else {
                system("cls");
                std::cout << "Great, you guessed the right number\n\n";
            }

        } while (rightNumber != input);


        // Asking if the User wants to play again
        point1:
        std::cout << "Do you want to play again?\n1. Yes\n2. No\n";
        std::cin >> option;

        if (option != 1 && option != 2) {
            std::cout << "Invalid input";
            goto point1;
            return 1;
        }
    } while (option == 1);
    
    return 0;
}