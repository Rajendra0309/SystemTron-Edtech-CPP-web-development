#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    
    int secretNumber = std::rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Can you guess it?" << std::endl;

    
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;
        
        if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n" << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n" << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}
