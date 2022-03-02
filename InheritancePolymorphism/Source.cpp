#include <iostream>
#include <string>
#include "Game.h"
#include "NumberGuess.h"
#include "MM.h"


int main() {

	Game* gamePtr = new MM();
	gamePtr->play();

	return 0;
}