#include "Puzzle.h"
#include "PuzzleState.h"
#include <queue>
#include <unordered_map>

// using boost::hash_combine
template <class T>
inline void hash_combine(std::size_t &seed, T const &v)
{
	seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T>
struct hash<vector<T>>
{
	typedef vector<T> argument_type;
	typedef std::size_t result_type;
	result_type operator()(argument_type const &in) const
	{
		size_t size = in.size();
		size_t seed = 0;
		for (size_t i = 0; i < size; i++)
			// Combine the hash of the current vector with the hashes of the previous ones
			hash_combine(seed, in[i]);
		return seed;
	}
};

bool Puzzle::solve(std::function<bool(PuzzleState *, PuzzleState *)> func, int option)
{
	int count = 0;
	int frontierLength = 0;
	PuzzleState* looking;

	// initialize the frontier with the initial state
	priority_queue<PuzzleState *, vector<PuzzleState *>, std::function<bool(PuzzleState *, PuzzleState *)>> frontier(func);
	unordered_map<std::vector<int>, PuzzleState*, hash<vector<int>>> explored;
	frontier.push(initial_state);

	// while frontier isn't empty,
	while (!frontier.empty())
	{
		count++;
		frontierLength = max(frontierLength, static_cast<int>(frontier.size()));
		// remove optimal leaf node from frontier
		looking = frontier.top();
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
		explored.insert({looking->grid, looking});

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

			if (explored.find(looking->nextStates[i]->grid) != explored.end()) 
			{
				frontier.push(looking->nextStates[i]);
				explored.insert({looking->nextStates[i]->grid,looking->nextStates[i]});
			}
		}
	}
	std::cout << "Did not find a solution :(";
	std::cout << "To solve this problem we expanded a total of " << count - 1 << " nodes\n";
	std::cout << "The maximum number of nodes in the queue at one time: " << frontierLength << endl;
	std::cout << "The depth of the goal node was " << looking->g << endl << endl;
	return false;
}