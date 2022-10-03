#include "Console-interaction.h"
#include <iostream>
#include <string>



using namespace std;


consoleObject::consoleObject() 
{
	INITIALIZE_CONSOLE_INTERACTION_DYNAMIC_LENGTH
	for (int i = 0; i < length; i++)
	{
		this->bank[i] = new Individual();
	}
}

void consoleObject::printBothSides() 
{
	INITIALIZE_CONSOLE_INTERACTION_DYNAMIC_LENGTH
		for (int i = 0; i < length; i++)
		{
			string line = "Hand " + to_string(i);
			line += ": ";
			
			Individual *hand = this->bank[i];
			int numberOfHands = hand->getNumberOfHands();
			for (int o = 0; o < numberOfHands; o++)
			{
				line += hand->getFingersOnHand(o) + " ";
			}
			line += "A";
			line += "\n\n";

			cout << line;
		}
}