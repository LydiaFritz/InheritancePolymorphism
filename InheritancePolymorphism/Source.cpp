#include <iostream>
#include <string>
#include "Game.h"
#include "NumberGuess.h"
#include "MM.h"
#include "TicTacToe.h"


int main() {

	Game* gamePtr = new TicTacToe();
	gamePtr->play();

	return 0;
}