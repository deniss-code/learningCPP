#include <iostream>
#include <random>

int main() {
	std::string options[3] = { "Rock","Paper","Scissors" };
    int decision;


    std::cout << "What do you choose?\n1. Rock\n2. Paper\n 3. Scissors\n";
    std::cin >> decision;

    std::random_device seed;
    std::default_random_engine e1(seed());
    std::uniform_int_distribution<int> uniform_dist(0, 2);
    int pcDecision = uniform_dist(e1);

    switch (decision)
    {
        case 1:
            if (pcDecision == 2) {
                std::cout << "You"
            }
            break;
        default:
            break;
    }
}