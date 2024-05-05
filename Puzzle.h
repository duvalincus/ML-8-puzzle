#include "PuzzleState.h"
class Euclidian
{
public:
	bool operator()(PuzzleState* a, PuzzleState* b)
	{
		return (a->g + a->getEuclidianDistance()) > (b->g + b->getEuclidianDistance());
	}
};

class Uniform
{
public:
	bool operator()(PuzzleState* a, PuzzleState* b) {
		return (a->g > b->g);
	}
};

class Misplaced
{
public:
	bool operator()(PuzzleState* a, PuzzleState* b) {
		return a->getMisplaced() < b->getMisplaced();
	}
};

class Puzzle
{
public:
	PuzzleState *initial_state, *goal_state;
	Puzzle(PuzzleState* initial, PuzzleState* goal)
		: initial_state(initial), goal_state(goal) {}
	bool solve(int);
};
