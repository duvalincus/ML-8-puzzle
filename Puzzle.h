#include "PuzzleState.h"
class Puzzle {
  private:
    PuzzleState initial_state, goal_state;

  public: 
    Puzzle(PuzzleState initial, PuzzleState goal) 
      : initial_state(initial), goal_state(goal) {}
    enum operators {
      left = -1, right = 1, up = -3, down = 3
    };
    int getEuclidianDistance(PuzzleState state);
    int getMisplaced(PuzzleState state); 
    PuzzleState getInitialState() {return initial_state;};
    PuzzleState getGoalState() {return goal_state;};



    
};