#include "PuzzleState.h"

int PuzzleState::getEuclidianDistance() {
  int distance = 0;
  for (auto i : grid) {
    
  }
};

int PuzzleState::getMisplaced() {
  int distance = 0;
  for (int i = 0; i < grid.size(); i++) {
    if (grid[i] != i) {
      distance++;
    }
  }
  return distance - 1;
}