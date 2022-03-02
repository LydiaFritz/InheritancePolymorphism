#include <iostream>
#include <string>
#include "Game.h"
#include "NumberGuess.h"

int main() {

	Game* gamePtr = new NumberGuess();
	gamePtr->play();

	return 0;
}