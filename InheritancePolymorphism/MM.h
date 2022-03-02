#ifndef MM_H
#define MM_H

#include <iostream>
#include <vector>
#include "MM_Guess.h"
#include "Game.h"

class MM : public Game {
private:

	MM_Guess currGuess;
	MM_Guess secretCode;

	int numGuesses;
	int whitePegs;
	int blackPegs;
	void getUserGuess();
	bool isWinner();
	bool outOfGuesses();

public:
	MM() {
		numGuesses = 0;
		secretCode.setMaster();
		whitePegs = blackPegs = 0;
	}
	void generateFeedback();
	//override from Game
	void play();
};

void MM::getUserGuess()
{
	cout << "Enter 4 integers: (1, 2, 3, 4, 5, or 6)  ";
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	currGuess.setGuess(a, b, c, d);
	numGuesses++;

}

bool MM::isWinner()
{
	return blackPegs == 4;
}

bool MM::outOfGuesses()
{
	return numGuesses == 5;
}

void MM::generateFeedback()
{

	whitePegs = blackPegs = 0;
	//count black pegs first
	for (int i = 0; i < 4; i++)
	{
		if (currGuess[i] == secretCode[i])
			blackPegs++;
	}
	//count white pegs next
	int guess[6], ans[6];
	for (int i = 0; i < 6; i++) {
		guess[i] = ans[i] = 0;
	}

	for (int j = 0; j < 4; j++) {
		guess[currGuess[j] - 1]++;
		ans[secretCode[j] - 1]++;
	}

	//now find the min occurrences for each color
	for (int j = 0; j < 6; j++) {
		whitePegs += guess[j] < ans[j] ? guess[j] : ans[j];
	}

	whitePegs -= blackPegs;

	cout << whitePegs << " white pegs and " << blackPegs << " black pegs." << endl;
}

//override function
void MM::play()
{
	//show guess for debug
	//cout << secretCode[0] << " " << secretCode[1] << " " << secretCode[2] << " " << secretCode[3] << endl;
	while (!isWinner() && !outOfGuesses()) {
		getUserGuess();
		generateFeedback();
	}
	if (isWinner())
		cout << "You win!" << endl;
	else
		cout << "Better luck next time..." << endl;

	cout << "Secret code was " << secretCode[0] << " " << secretCode[1] << " " << secretCode[2] << " " << secretCode[3] << endl;
}


#endif