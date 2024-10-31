#include <iostream>
#include <random>

int main() {
	std::string options[3] = { "Rock","Paper","Scissors" };
    int decision;


    std::cout << "What do you choose?\n1. Rock\n2. Paper\n3. Scissors\n";
    std::cin >> decision;

    std::random_device seed;
    std::default_random_engine e1(seed());
    std::uniform_int_distribution<int> uniform_dist(0, 2);
    int pcDecision = uniform_dist(e1);
    decision -= 1;

    if (options[decision] == options[pcDecision]) {
        std::cout << "You have a tie with " << options[pcDecision];
    }
    else if (options[pcDecision] == "Paper" && options[decision] == "Scissors") {
        std::cout << "You have won against " << options[pcDecision];
    }
    else if (options[pcDecision] == "Rock" && options[decision] == "Paper") {
        std::cout << "You have won against " << options[pcDecision];
    }
    else if (options[pcDecision] == "Scissors" && options[decision] == "Paper") {
        std::cout << "You have won against " << options[pcDecision];
    }
    else {
        std::cout << "You have lost against " << options[pcDecision];
    }
} 