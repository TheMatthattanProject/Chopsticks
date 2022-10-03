#define AMOUNT_OF_HANDS 2
#define FINGERS_PER_HAND 4

using namespace std;

class Individual
{
	public:
		int hands[AMOUNT_OF_HANDS];
		Individual();
		bool aliveNextRound(Individual &opponent);
		bool receiveChopsticks(int chopstickAmount, int handNumber);

	private:
		int fingersPerHand = FINGERS_PER_HAND;
};


Individual::Individual() 
{
	int length = sizeof(this->hands) / sizeof(this->hands[0]);
	for (int i = 0; i < length; i++) 
	{
		this->hands[i] = 1;
	}
}


bool Individual::aliveNextRound(Individual& opponent) 
{
	// Check that exactly one hand is left 
	int length = sizeof(this->hands) / sizeof(this->hands[0]);
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
	int length = sizeof(this->hands) / sizeof(this->hands[0]);
	
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
	if (val + 1 > this->fingersPerHand) 
	{
		this->hands[handNumber] = 0;
		return true;
	}

	return false;
}
