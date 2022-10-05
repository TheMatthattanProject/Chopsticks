#pragma once

#include "Individual.h"


#define INITIALIZE_CONSOLE_INTERACTION_DYNAMIC_LENGTH int length = sizeof(this->bank) / sizeof(this->bank[0]);

class Game
{
public:
	void takeTurns();
	void haveTurn(int turnTaker, int opponent, int turnHand, int opponentHand);
	void printBothSides();
	Game();
private:
	Individual* bank[AMOUNT_OF_PLAYERS];
};