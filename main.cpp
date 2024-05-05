#include <iostream>
#include <functional>
#include "PuzzleState.h"
#include "Puzzle.h"
#include <vector>

using namespace std;

Puzzle Create_Puzzle(int);
void Menu();

int main()
{
    // Puzzle Current_Puzzle = Create_Puzzle(9); // inital input
    Puzzle Current_Puzzle(new PuzzleState({1,2,3,4,5,0,7,8,6}), new PuzzleState({1,2,3,4,5,6,7,8,0}));
    //=====================start of menu=========================
    int userinput = 6;
    while (userinput != 0)
    {
        Menu();
        cin >> userinput; // take in input
        if (userinput == 1)
        {
            cout << "Current Imputed Puzzle:\n";
            cout << Current_Puzzle.initial_state; // Display current Puzzle
        }
        if (userinput == 2)
        {
            Current_Puzzle = Create_Puzzle(9); // create new puzzle
        }
        if (userinput == 3)
        {
            //Solve using Uniform cost
            Current_Puzzle.solve(userinput);
        }
        if (userinput == 4)
        {
            // Solve using A* with the Misplaced Tile heuristic
            Current_Puzzle.solve(userinput);
        }
        if (userinput == 5)
        {
            // Solve using A* with the Euclidean Distance heuristic
            Current_Puzzle.solve(userinput);
        }
        if (userinput > 5 || userinput < 0)
        {
            cout << "Invalid input please select again!";
        }
    }
}

void Menu()
{
    cout << "Please Select a option:" << endl;
    cout << "1 - Display current puzzle\n";
    cout << "2 - Create New Puzzle\n";
    cout << "3 - Solve using Uniform Cost Search\n";
    cout << "4 - A* with the Misplaced Tile heuristic\n";
    cout << "5 - A* with the Euclidean Distance heuristic\n";
    cout << "0 - Quit\n";
}

Puzzle Create_Puzzle(int size = 9)
{
    cout << "Please Input the inital Starting state of the puzzle in this format with 0 being the empty space for example:";
    cout << "\n 0 1 2\n 3 4 5\n 6 7 8\n";

    vector<int> C_Puzzle, goal;
    int userinput = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "For position " << i << endl;
        cin >> userinput;
        C_Puzzle.push_back(userinput);
    }

    //create goal state
    for (int i = 1; i < size; i++) {
        goal.push_back(i);
    }
    goal.push_back(0);

    Puzzle puzzle(new PuzzleState(C_Puzzle), new PuzzleState(goal));
    return puzzle;
}
