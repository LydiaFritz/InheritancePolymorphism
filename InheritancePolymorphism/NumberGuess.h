#ifndef NUMBER_GUESS_H
#define NUMBER_GUESS_H

#include "Game.h"

class NumberGuess : public Game {
private:

	int secretNumber;

public:

	//constructor
	NumberGuess();
	//override virtual Game::play()
	void play();
};

#endif
