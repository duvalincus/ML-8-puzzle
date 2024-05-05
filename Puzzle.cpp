#include "Puzzle.h"
#include "PuzzleState.h"
#include <queue>

bool Puzzle::solve(int option)
{
	int count = 0;
	int frontierLength = 0;
	// get the initial state of the problem
	PuzzleState *initial = initial_state;

	if (option == 3) {
		cout << "OPTION 3\n";
	// initialize the frontier with the initial state
		priority_queue<PuzzleState*, vector<PuzzleState*>, Uniform> frontier;
		vector<PuzzleState*> explored = {};
		frontier.push(initial);

		// while frontier isn't empty,
		while (!frontier.empty())
		{
			count++;
			frontierLength = max(frontierLength, static_cast<int>(frontier.size()));
			// remove optimal leaf node from frontier
			PuzzleState *looking = new PuzzleState(*frontier.top());
			frontier.pop();

			if (looking->grid == goal_state->grid)
			{
				cout << "Goal!\n";
				looking->trace();
				cout << "To solve this problem we expanded a total of " << count << " nodes\n";
				cout << "The maximum number of nodes in the queue at one time: " << frontierLength << endl;
				cout << "The depth of the goal node was " << looking->g << endl;
				return true;
			}
			// add the node to the explored set
			explored.push_back(looking);
			// add looking's possible next states to nextStates
			looking->enumerate();
			for (int i = 0; i < looking->nextStates.size(); i++)
			{
				bool flag = false;
				for (auto j : explored) if (j == looking->nextStates[i]) flag = true;
				if (!flag) frontier.push(looking->nextStates[i]);
			}
		}
	}
	// else if (option == 4) {
	// 	cout << "OPTION 4\n";

	// 	priority_queue<PuzzleState, vector<PuzzleState*>, Misplaced> frontier;
	// 	vector<PuzzleState> explored = {};
	// 	frontier.push(*initial);

	// 	// while frontier isn't empty,
	// 	while (!frontier.empty())
	// 	{
	// 		count++;
	// 		// remove optimal leaf node from frontier
	// 		PuzzleState looking = frontier.top();
	// 		frontier.pop();

	// 		if (looking.grid == goal_state->grid)
	// 		{
	// 			cout << "Goal!\n";
	// 			looking.trace();
	// 			cout << "To solve this problem we expanded a total of " << count << " nodes\n";
	// 			cout << "The maximum number of nodes in the queue at one time: " << endl;
	// 			cout << "The depth of the goal node was " << looking.g << endl;
	// 			return true;
	// 		}
	// 		// add looking's possible next states to nextStates
	// 		looking.enumerate();
	// 		for (int i = 0; i < looking.nextStates.size(); i++)
	// 		{
	// 			frontier.push(*looking.nextStates[i]);
	// 		}
	// 	}
	// }

	// else if (option == 5)
	// {
	// 	cout << "OPTION 5\n";
	// 	priority_queue<PuzzleState, vector<PuzzleState*>, Euclidian> frontier;
	// 	vector<PuzzleState> explored = {};
	// 	frontier.push(initial);

	// 	// while frontier isn't empty,
	// 	while (!frontier.empty())
	// 	{
	// 		count++;
	// 		// remove optimal leaf node from frontier
	// 		PuzzleState looking = frontier.top();
	// 		frontier.pop();

	// 		if (looking.grid == goal_state->grid)
	// 		{
	// 			cout << "Goal!\n";
	// 			looking.trace();
	// 			cout << "To solve this problem we expanded a total of " << count << " nodes\n";
	// 			cout << "The maximum number of nodes in the queue at one time: " << endl;
	// 			cout << "The depth of the goal node was " << looking.g << endl;
	// 			return true;
	// 		}
	// 		// add looking's possible next states to nextStates
	// 		looking.enumerate();
	// 		for (int i = 0; i < looking.nextStates.size(); i++)
	// 		{
	// 			frontier.push(*looking.nextStates[i]);
	// 		}
	// 	}
	// }
	cout << "Did not find a solution :(";
	return false;
}