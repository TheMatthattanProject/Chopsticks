#define AMOUNT_OF_HANDS 2

using namespace std;

class Individual
{
	public:
		int hands[AMOUNT_OF_HANDS];
		Individual();
		bool aliveNextRound(Individual &opponent);
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

	}



	// 



}