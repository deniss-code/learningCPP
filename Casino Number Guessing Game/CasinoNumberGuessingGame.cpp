#include <iostream>
#include <random>
#include <fstream>


int main() {
    // Clear console and declaration
    system("cls");
    int option = 0;
    int input;
    int difficultyOption;
    int minRange = 0;
    int maxRange = 0;

    class difficulty {
    public:
        int rangeMax;
    };
    difficulty easy;
    easy.rangeMax = 20;

    difficulty medium;
    medium.rangeMax = 50;

    difficulty hard;
    hard.rangeMax = 100;

    difficulty impossible;
    impossible.rangeMax = 10000;

    // Loop for the game
    do {
        // Ask for difficulty
        std::cout << "What difficulty do you want to play?\n1. Easy\n2. Medium\n3. Hard\n4. Impossible\n";
        std::cin >> difficultyOption;
        switch (difficultyOption) {
        case 1:
            maxRange = easy.rangeMax;
            break;
        case 2:
            maxRange = medium.rangeMax;
            break;
        case 3:
            maxRange = hard.rangeMax;
            break;
        case 4:
            maxRange = impossible.rangeMax;
            break;
        }



        //// Asking for input for the range
        //std::cout << "Till what number do you wanna guess?\n";
        //std::cin >> rangeMax;
        system("cls");

        // Generating the number

        std::random_device seed;
        std::default_random_engine e1(seed());
        std::uniform_int_distribution<int> uniform_dist(1, maxRange);
        int rightNumber = uniform_dist(e1);
        std::cout << "Guess the number between 1 and " << maxRange << "\n";
        
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