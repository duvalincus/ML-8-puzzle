#include "PuzzleState.h"
#include "Puzzle.h"
class Compare {
  public:
    bool operator()(PuzzleState a, PuzzleState b) {
      return  a.calculateDistance() > b.calculateDistance();
    }
};

