#include "PuzzleState.h"

class Puzzle
{
public:
	PuzzleState *initial_state, *goal_state;
	Puzzle(PuzzleState* initial, PuzzleState* goal)
		: initial_state(initial), goal_state(goal) {}
	bool solve(std::function<bool(PuzzleState*, PuzzleState*)> func, int);
};
