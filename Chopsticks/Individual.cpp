#include "Individual.h"
#include <iostream>



using namespace std;


int Individual::getNumberOfHands() 
{
	return sizeof(this->hands) / sizeof(this->hands[0]);
}


int Individual::getFingersOnHand(int handNumber) 
{
	if (handNumber < 0 || handNumber > this->fingersPerHand - 1)
	{
		return -1;
	}
	return this->hands[handNumber];
}

bool Individual::isDead()
{
	INITIALIZE_INDIVIDUAL_DYNAMIC_LENGTH
		for (int i = 0; i < length; i++)
		{
			if (this->hands[i] > 0) 
			{
				return false;
			}
		}
	return true;
}

bool Individual::operator==(Individual& obj)
{
	INITIALIZE_INDIVIDUAL_DYNAMIC_LENGTH
	int opponentLength = obj.getNumberOfHands();
	int matching = 0;

		for (int i = 0; i < length; i++)
		{
			for (int o = 0; o < opponentLength; o++)
			{
				if (this->hands[i] == obj.getFingersOnHand(o))
				{
					matching++;
					break;
				}
			}
		}

		if (matching > this->getNumberOfHands() - 1)
		{
			return true;
		}

		return false;
	
}


Individual::Individual() 
{
	INITIALIZE_INDIVIDUAL_DYNAMIC_LENGTH
	for (int i = 0; i < length; i++) 
	{
		this->hands[i] = 1;
	}
}





bool Individual::aliveNextRound(Individual& opponent) 
{
	// Check that exactly one hand is left 
	INITIALIZE_INDIVIDUAL_DYNAMIC_LENGTH
	int handsLeft = 0;
	int lastHandPos = 0;

	for (int i = 0; i < length; i++) 
	{
		if (this->hands[i] != 0)
		{
			handsLeft++;
		}

		if (handsLeft > 1)
		{
			return true;
		}

		lastHandPos = i;
	}


	// Get max value from opponent
	int opponentMax = 0;

	for (int i = 0; i < length; i++)
	{
		int current = opponent.hands[i];
		if (current > opponentMax)
		{
			opponentMax = current;
		}
	}


	// Check if opponents max move defeats last finger
	if (opponentMax + this->hands[lastHandPos] > this->fingersPerHand)
	{
		return true;
	}

	return false;
}



bool Individual::receiveChopsticks(int chopstickAmount, int handNumber) 
{
	INITIALIZE_INDIVIDUAL_DYNAMIC_LENGTH
	
	// Prevent segfaults
	// Convert to lazy evaluation a
	if (handNumber < 0 || handNumber > length - 1)
	{
		return false;
	}

	// Prevent cheating / mistakes
	if (chopstickAmount < 1 || chopstickAmount > this->fingersPerHand + 1)
	{
		return false;
	}

	// Return true if the hand dies
	int val = this->hands[handNumber] += chopstickAmount;
	//cout << "This is val of hand and hand value\n" << "val: " << val << "\nthis->hands[" << handNumber << "]: " << this->hands[handNumber] << "\n Chopstick Amount: " << chopstickAmount <<endl;
	if (val > this->fingersPerHand) 
	{
		this->hands[handNumber] = 0;
		return true;
	}

	return false;
}
