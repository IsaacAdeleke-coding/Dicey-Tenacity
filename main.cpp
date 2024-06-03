//
//  main.cpp
//  Dicey Tenacity
//
//  Created by Isaac Adeleke on 6/3/24.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed the random number generator

    int targetScore = 10;
    int dice1, dice2, totalScore = 0;
    int rollCount = 10; // Player starts with 10 rolls
    char rollAgain = 'y';

    std::cout << "Welcome to the Challenging Dice Game!" << std::endl;
    std::cout << "Try to hit a target score of " << targetScore << " within " << rollCount << " rolls." << std::endl;
    std::cout << "Be careful: rolling a total of 7 will cost you an extra roll!" << std::endl;

    while (rollAgain == 'y' && rollCount > 0) {
        dice1 = std::rand() % 6 + 1; // Generate random roll for dice 1 (1-6)
        dice2 = std::rand() % 6 + 1; // Generate random roll for dice 2 (1-6)
        totalScore = dice1 + dice2;

        std::cout << "You rolled a " << dice1 << " and a " << dice2 << ". Total: " << totalScore << std::endl;

        // Decrease roll count
        rollCount--;

        // Check for penalty
        if (totalScore == 7) {
            rollCount--;
            std::cout << "Penalty! Rolling a 7 costs you an extra roll. Rolls left: " << rollCount << std::endl;
        }

        if (totalScore == targetScore) {
            std::cout << "Congratulations! You hit the target score and won!" << std::endl;
            break;
        }

        if (rollCount > 0) {
            std::cout << "Rolls left: " << rollCount << ". Would you like to roll again? (y/n): ";
            std::cin >> rollAgain;
        } else {
            std::cout << "No rolls left! Game over." << std::endl;
        }
    }

    if (totalScore != targetScore && rollCount <= 0) {
        std::cout << "You didn't hit the target score. Game over! Better luck next time!" << std::endl;
    }

    return 0;
}
