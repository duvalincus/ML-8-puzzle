#pragma once
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class PuzzleState {
public:
    std::vector<int> grid;
    PuzzleState* previous = nullptr;
    std::vector<PuzzleState*> nextStates = {};
    int g = 0;

    PuzzleState(std::vector<int> grid = {0,0,0,0,0}, int cost = 0, PuzzleState* previous = nullptr): 
        grid(grid), g(cost), previous(previous) {}

    double getEuclidianDistance();
    int getMisplaced();
    void enumerate();
    void trace() {
        PuzzleState* currState = this;
        while (currState != nullptr)
        {
            cout << *currState;
            currState = currState->previous;
        }
    }

    enum operators
    {
        left = -1,
        right = 1,
        up = -1,
        down = 1
    };

    friend ostream &operator<<(ostream &os, const PuzzleState &state)
    {
        int bound = sqrt(state.grid.size());

        for (int i = 0; i < bound; i++)
        {
            for (int j = 0; j < bound; j++)
            {
                os << state.grid[bound * i + j] << " ";
            }
            os << endl;
        }
        return os;
    }
};