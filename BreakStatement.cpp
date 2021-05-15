// Copyright (c) 2021 Youngjun Kim rights reserved
//
// Created by: Youngjun Kim
// Created on: May 2021
// This program checks if guessed number is correct or incorrect

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function checks if guessed number is correct or incorrect
    int someRandomNumber;
    std::string integerAsString;
    int integerAsNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    someRandomNumber = idist(rgen);
    while (true) {

    // input
    std::cout << "Can you guess the number I choose from 0 to 9?" << std::endl;
    std::cout << "Enter the guessed number: ";
    std::cin >> integerAsString;
    std::cout << "" << std::endl;

    // process
    try {
        integerAsNumber = std::stoi(integerAsString);
        
        if (integerAsNumber < 0) {
            // output
            std::cout << "This number is a negative";
            std::cout << "" << std::endl;
        } else if (integerAsNumber == someRandomNumber) {
            // output
            std::cout << "Correct!";
            std::cout << "" << std::endl;
            std::cout << "random number is " << someRandomNumber << std::endl;
            break;
        } else {
            std::cout << "Incorrect";
            std::cout << "" << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "That was not valid input";
        std::cout << "" << std::endl;
    }
    }
}
