#pragma once

#define AMOUNT_OF_HANDS 2
#define FINGERS_PER_HAND 4
#define AMOUNT_OF_PLAYERS 2
#define INITIALIZE_INDIVIDUAL_DYNAMIC_LENGTH int length = getNumberOfHands();

class Individual
{
public:
	Individual();
	bool aliveNextRound(Individual& opponent);
	bool receiveChopsticks(int chopstickAmount, int handNumber);
	int getNumberOfHands();
	int getFingersOnHand(int handNumber);

private:
	int fingersPerHand = FINGERS_PER_HAND;
	int hands[AMOUNT_OF_HANDS];
};
