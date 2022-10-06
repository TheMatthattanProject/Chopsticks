#pragma once
#include "Individual.h"
#include <vector>


class Node
{
public:
	std::vector<Individual*> possibleMoves();
	Individual* cell;
	Individual* opponent;
	int level;

};
