#include "Game.h"
#include <iostream>
#include <string>
#include <queue>
#include "Node.h"



using namespace std;


Game::Game() 
{
	INITIALIZE_CONSOLE_INTERACTION_DYNAMIC_LENGTH
	for (int i = 0; i < length; i++)
	{
		this->bank[i] = new Individual();
	}
}

void Game::takeTurns()
{
	// Have turn
	// Check if dead, stop if so
	// Print screen
	// Change turn taker
	int handTurn = 0;
	int opponent = 1;
	this->printBothSides();
	while (true) {

		

		int taggingTurn;
		int taggedTurn;
		cout << "Turn " << to_string(handTurn + 1) << endl;
		cout << "Which hand would you like to use?\n";
		cin >> taggingTurn;
		taggingTurn--;

		cout << "Select which opponent hand?\n";
		cin >> taggedTurn;
		taggedTurn--;



		this->haveTurn(handTurn, opponent, taggingTurn, taggedTurn);
		
		if (this->bank[opponent]->isDead())
		{
			cout << "You win!! Game over.\n";
			return;

		}

		// Print Screen
		this->printBothSides();


		//swap turns 
		int temp = opponent;
		opponent = handTurn;
		handTurn = temp;



	}
}

void Game::haveTurn(int turnTaker, int opponent, int turnHand, int opponentHand)
{
	cout << "Fingers of attacking hand: " << this->bank[turnTaker]->getFingersOnHand(turnHand) << endl;
	this->bank[opponent]->receiveChopsticks(this->bank[turnTaker]->getFingersOnHand(turnHand), opponentHand);
}

void Game::printBothSides()
{
	INITIALIZE_CONSOLE_INTERACTION_DYNAMIC_LENGTH
		for (int i = 0; i < length; i++)
		{
			string line = "Hand " + to_string(i + 1);
			line += ": ";
			
			Individual *hand = this->bank[i];
			int numberOfHands = hand->getNumberOfHands();
			for (int o = 0; o < numberOfHands; o++)
			{
				line += to_string(hand->getFingersOnHand(o)) + "  ";
			}
			line += "\n\n";

			cout << line;
		}
}

void Game::BFSNodes(int levels)
{
	int current_level = 0;
	queue<Node*> bank;

	//First node
	Node* first = new Node();
	first->cell = new Individual();
	first->level = 0;
	bank.push(first);

	while (current_level < levels)
	{
		//Generate possible moves needs to be Individual function
	}
}
