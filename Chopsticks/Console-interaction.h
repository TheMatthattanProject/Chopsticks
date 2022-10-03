#pragma once

#include "Individual.h"


#define INITIALIZE_CONSOLE_INTERACTION_DYNAMIC_LENGTH int length = sizeof(this->bank) / sizeof(this->bank[0]);

class consoleObject
{
public:
	void takeTurns();
	void printBothSides();
	consoleObject();
private:
	Individual* bank[AMOUNT_OF_PLAYERS];
};