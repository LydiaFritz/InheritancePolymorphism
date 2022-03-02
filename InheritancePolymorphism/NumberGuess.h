#ifndef NUMBER_GUESS_H
#define NUMBER_GUESS_H

#include "Game.h"

class NumberGuess : public Game {
private:

	int secretNumber = -1;
	const int MIN = 1, MAX = 1000;

public:

	//constructor
	NumberGuess();
	//override virtual Game::play()
	void play();
};

NumberGuess::NumberGuess() :Game("Number Guess", 1) {
	srand(time(NULL));
	//secretNumber will be set with random number in play()
}

void NumberGuess::play() {
	int guess, currGuess = 0, newLow = MIN, newHi = MAX;
	bool winner = false;

	secretNumber = (rand() % 1000) + 1;
	std::cout << "Welcome to Number Guess!\n";
	std::cout << "You get 10 guesses to guess the secret number." << std::endl;
	do {
		//get the guess
		std::cout << "Enter a number between " << newLow << " and " << newHi << " ";
		std::cin >> guess;
		//count it
		currGuess++;
		//evaluate it
		if (guess == secretNumber) {
			std::cout << "YOU WIN" << std::endl;
			winner = true;
		}
		else if (guess < secretNumber) {
			std::cout << "Too low..." << std::endl;
			newLow = guess + 1;
		}
		else {
			std::cout << "Too high..." << std::endl;
			newHi = guess - 1;
		}
	} while (!winner && currGuess < 10);


}

#endif
