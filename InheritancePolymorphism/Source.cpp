#include <iostream>
#include <string>
#include "GameUtility.h"



int main() {

	Game* gamePtr = new TicTacToe();
	gamePtr->play();

	return 0;
}