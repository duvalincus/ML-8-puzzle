#pragma once
#include <vector>

class PuzzleState {
public:
    std::vector<int> grid;
    PuzzleState* previous = nullptr;
    std::vector<PuzzleState*> nextStates = {};

    PuzzleState(std::vector<int> grid = {0,0,0,0,0}, PuzzleState* previous = nullptr): 
        grid(grid), previous(previous) {}

    int getEuclidianDistance();
    int getMisplaced();
};