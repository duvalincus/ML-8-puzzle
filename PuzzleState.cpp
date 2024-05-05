#include "PuzzleState.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// TODO fix euclidian distance problem
double PuzzleState::getEuclidianDistance()
{
	vector<int> Goal_State;
	int size = grid.size();
	for (int i = 1; i < size; i++)
	{
		Goal_State.push_back(i);
	}
	Goal_State.push_back(0);

	// Calculate puzzle dimensions
	int puzzle_size = static_cast<int>(sqrt(size));
	double TotalEU = 0;

	// Calculate Euclidean distance for each pair of elements and add to TotalEU
	for (int k = 0; k < grid.size(); k++)
	{
		if (grid[k] != 0)
		{
			int user_row = k / puzzle_size + 1;
			int user_col = k % puzzle_size + 1;
			int goal_index = find(Goal_State.begin(), Goal_State.end(), grid[k]) -
							 Goal_State.begin();
			int goal_row = goal_index / puzzle_size + 1;
			int goal_col = goal_index % puzzle_size + 1;
			double distance =
				sqrt(pow(goal_row - user_row, 2) + pow(goal_col - user_col, 2));
			TotalEU += distance;
		}
	}

	return TotalEU;
};

int PuzzleState::getMisplaced()
{
	int distance = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		if (grid[i] != i + 1)
		{
			distance++;
		}
	}
	return distance - 1;
}

// needs testing
void PuzzleState::enumerate()
{
	int row = 0;
	int col = 0;
	int bound = sqrt(grid.size());
	int newpos = 0;
	vector<int> newGrid;
	for (int i = 0; i < bound; i++)
	{
		for (int j = 0; j < bound; j++)
		{
			if (grid[bound * i + j] == 0)
			{
				row = i;
				col = j;
			}
		}
	}

	int oldpos = row * bound + col;

	// push next possible states depending on position to nextStates
	if ((newpos = col + left) >= 0)
	{
		newGrid = grid;
		newGrid[row * bound + newpos] = grid[oldpos];
		newGrid[oldpos] = grid[row * bound + newpos];

		nextStates.push_back(new PuzzleState(newGrid, g + 1, this));
	}
	if ((newpos = col + right) < bound)
	{
		newGrid = grid;
		newGrid[row * bound + newpos] = grid[oldpos];
		newGrid[oldpos] = grid[row * bound + newpos];

		nextStates.push_back(new PuzzleState(newGrid, g + 1, this));
	}
	if ((newpos = row + down) < bound)
	{
		newGrid = grid;
		newGrid[newpos * bound + col] = grid[oldpos];
		newGrid[oldpos] = grid[newpos * bound + col];

		nextStates.push_back(new PuzzleState(newGrid, g + 1, this));
	}
	if ((newpos = row + up) >= 0)
	{
		newGrid = grid;
		newGrid[newpos * bound + col] = grid[oldpos];
		newGrid[oldpos] = grid[newpos * bound + col];

		nextStates.push_back(new PuzzleState(newGrid, g + 1, this));
	}
}