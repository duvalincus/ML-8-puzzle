#include <iostream>
#include <vector>

using namespace std;

vector<int> Create_Puzzle() 
{
    cout << "Please Input the inital Starting state of the puzzle in this format with 0 being the empty space:";
    cout <<"\n 0 1 2\n 3 4 5\n 6 7 8\n";
    

    vector<int> C_Puzzle;
    int userinput = 0;

    for(int i = 0; i < 9; i++) {
        cout << "For position " << i << endl;
        cin >> userinput;
        C_Puzzle.push_back(userinput);
    }
return C_Puzzle;
}

void Output_Puzzle(vector<int> C_Puzzle) 
{
    int count = 0;
    for(int i = 0; i < C_Puzzle.size(); i++) {
        cout << C_Puzzle[i] << " ";
        count++;
        if(count == 3) {
            cout << endl;
            count = 0;
        }
    }
}

void Menu()
{            
    cout << "Please Select a option:"<<endl;
    cout << "1 - Display current puzzle\n";
    cout << "2 - Create New Puzzle\n";
    cout << "3 - Solve using Uniform Cost Search\n";
        //Solve 
    cout << "4 - A* with the Misplaced Tile heuristic\n";
        //solve
    cout << "5 - A* with the Euclidean Distance heuristic\n";
        //solve
    cout << "0 - Quit\n";
        //quit
}

int main() {

vector<int> Current_Puzzle;

Current_Puzzle = Create_Puzzle(); //inital input
//=====================start of menu=========================
int userinput = 6;
while (userinput != 0)
{
    Menu();
    cin >> userinput; // take in input
        if (userinput == 1)
        {
            cout<<"Current Imputed Puzzle:\n";
            Output_Puzzle(Current_Puzzle);      //Display current Puzzle
        }
        if (userinput ==2)
        {
            Current_Puzzle = Create_Puzzle();   //create new puzzle
        }
        if (userinput ==3)
        {
            //Solve using Uniform Cost Search
        }
                if (userinput == 4)
        {
            //Solve using A* with the Misplaced Tile heuristic
        }
                if (userinput == 5)
        {
            //Solve using A* with the Euclidean Distance heuristic
        }
                if (userinput > 5 || userinput < 0)
        {
            cout << "Invalid input please select again!";
        }
}

}