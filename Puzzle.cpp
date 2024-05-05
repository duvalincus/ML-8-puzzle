#include "Puzzle.h"
#include "PuzzleState.h"
#include <queue>

bool checkFrontier(priority_queue<PuzzleState *, vector<PuzzleState *>, std::function<bool(PuzzleState *, PuzzleState *)>> frontier,
					PuzzleState* check) {
	while (!frontier.empty()) {
		if (frontier.top()->grid == check->grid) return true;
		frontier.pop();
	}
	return false;
}

bool Puzzle::solve(std::function<bool(PuzzleState *, PuzzleState *)> func, int option)
{
	int count = 0;
	int frontierLength = 0;

	// initialize the frontier with the initial state
	priority_queue<PuzzleState *, vector<PuzzleState *>, std::function<bool(PuzzleState *, PuzzleState *)>> frontier(func);
	vector<PuzzleState*> explored = {};
	frontier.push(initial_state);

	// while frontier isn't empty,
	while (!frontier.empty())
	{
		count++;
		frontierLength = max(frontierLength, static_cast<int>(frontier.size()));
		// remove optimal leaf node from frontier
		PuzzleState *looking = frontier.top();
		frontier.pop();

		if (looking->grid == goal_state->grid)
		{
			std::cout << "Goal!\n";
			looking->trace();
			std::cout << "To solve this problem we expanded a total of " << count - 1 << " nodes\n";
			std::cout << "The maximum number of nodes in the queue at one time: " << frontierLength << endl;
			std::cout << "The depth of the goal node was " << looking->g << endl << endl;
			return true;
		}

		// add the node to the explored set
		explored.push_back(looking);

		// add looking's possible next states to nextStates
		cout << "The best state to expand with g(n) = " << looking->g << endl;
		if (option == 5)
			cout << "and h(n) = " << looking->getEuclidianDistance() << endl;
		else if (option == 4)
			cout << "and h(n) = " << looking->getMisplaced() << endl;
		cout << *looking << "Expanding.." << endl;
		looking->enumerate();

		// add valid states from nextStates into the frontier 
		for (int i = 0; i < looking->nextStates.size(); i++)
		{

			bool flag = false;
			for (auto j : explored) if (j == looking->nextStates[i] || checkFrontier(frontier, looking)) flag = true;
			if (!flag) frontier.push(looking->nextStates[i]);
		}
	}
	std::cout << "Did not find a solution :(";
	return false;
}