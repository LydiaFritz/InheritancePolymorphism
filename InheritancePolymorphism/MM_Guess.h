#ifndef MM_GUESS_H
#define MM_GUESS_H

#include <ctime>
#include <utility>

using namespace std;

class MM_Guess {
private:
	int aGuess[4];
	bool isValid(int);
public:
	MM_Guess();
	void setGuess(int, int, int, int);
	void setMaster();
	int operator[](int index) { return aGuess[index]; }
};



bool MM_Guess::isValid(int ch) {
	return ch >= 1 && ch <= 6;
}

void MM_Guess::setMaster()
{
	aGuess[0] = rand() % 6 + 1;
	aGuess[1] = rand() % 6 + 1;
	aGuess[2] = rand() % 6 + 1;
	aGuess[3] = rand() % 6 + 1;
}

inline MM_Guess::MM_Guess()
{
	srand(time(0));
	aGuess[0] = aGuess[1] = aGuess[2] = aGuess[3] = -1;

}

void MM_Guess::setGuess(int a, int b, int c, int d)
{
	if (isValid(a))	aGuess[0] = a; else aGuess[0] = -1;
	if (isValid(b))	aGuess[1] = b; else aGuess[0] = -1;
	if (isValid(c))	aGuess[2] = c; else aGuess[0] = -1;
	if (isValid(d))  aGuess[3] = d; else aGuess[0] = -1;
}


#endif