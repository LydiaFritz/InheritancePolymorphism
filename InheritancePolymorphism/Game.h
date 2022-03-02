#ifndef GAME_H
#define GAME_H

/*
* Abstract Game class
* contains play()
*/

#include <string>

class Game {
private:
	std::string name;
	int numPlayers;
public:
	Game() :name(""), numPlayers(0) {}
	Game(std::string n, int num_players) {
		name = n;
		numPlayers = num_players;
	}

	void setName(std::string newName) { name = newName; }
	void setNumPlayers(int np) { numPlayers = np; }

	int getNumPlayers()const { return numPlayers; }
	std::string getName()const { return name; }

	virtual void play() = 0;

};

#endif
