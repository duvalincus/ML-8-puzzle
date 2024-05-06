#include <iostream>
#include "PuzzleState.h"
#include "Puzzle.h"
#include <functional>
#include <vector>

using namespace std;

Puzzle Create_Puzzle(int);
void Menu();
bool Euclidian(PuzzleState *a, PuzzleState *b)
{
    return (a->g + a->getEuclidianDistance()) > (b->g + b->getEuclidianDistance());
}
bool Uniform(PuzzleState *a, PuzzleState *b)
{
    return (a->g > b->g);
}
bool Misplaced(PuzzleState *a, PuzzleState *b)
{
    return a->getMisplaced() > b->getMisplaced();
}

int main()
{
    // Puzzle Current_Puzzle = Create_Puzzle(9); // inital input
    vector<int> solved = {1,2,3,4,5,6,7,8,0};
    vector<int> easy = {1,2,0,4,5,3,7,8,6};
    vector<int> veryEasy = {1,2,3,4,5,6,7,0,8};
    vector<int> doable = {0,1,2,4,5,3,7,8,6};
    vector<int> ohBoy = {8, 7, 1, 6, 0, 2, 5, 4, 3};
    vector<int> impossible = {1,2,3,4,5,6,8,7,0};

    Puzzle Current_Puzzle(new PuzzleState(impossible), new PuzzleState(solved));
    //=====================start of menu=========================
    int userinput = 6;
    while (userinput != 0)
    {
        Menu();
        cin >> userinput; // take in input
        if (userinput == 1)
        {
            cout << "Current Imputed Puzzle:\n";
            cout << *Current_Puzzle.initial_state; // Display current Puzzle
        }
        if (userinput == 2)
        {
            Current_Puzzle = Create_Puzzle(9); // create new puzzle
        }
        if (userinput == 3)
        {
            //Solve using Uniform cost
            Current_Puzzle.solve(Uniform, userinput);
        }
        if (userinput == 4)
        {
            // Solve using A* with the Misplaced Tile heuristic
            Current_Puzzle.solve(Misplaced, userinput);
        }
        if (userinput == 5)
        {
            // Solve using A* with the Euclidean Distance heuristic
            Current_Puzzle.solve(Euclidian, userinput);
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
