#include <iostream>
#include <queue>
#include <functional>
#include <PuzzleState.h>
#include <Puzzle.h>
using std::cout;
using std::endl;

int main() {
    cout << "Hello world" << endl;
    
}

bool graphSearch(Puzzle problem) {
    //get the initial state of the problem
    PuzzleState initial = problem.getInitialState();

    //initialize the frontier with the initial state
    std::priority_queue<PuzzleState> frontier;
    std::vector<PuzzleState> explored;
    frontier.push(initial);

    //while frontier isn't empty, 
    while (!frontier.empty()){
        PuzzleState looking = frontier.top();
    }

}