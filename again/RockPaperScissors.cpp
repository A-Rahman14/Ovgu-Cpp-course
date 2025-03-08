#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */
bool beats(int choice1, int choice2)
{
    // Insert your code here
    switch (choice1)
    {
    case 1:
        return choice2 == 3 ? true : false;
    case 2:
        return choice2 == 1 ? true : false;
    case 3:
        return choice2 == 2 ? true : false;
    default:
        return false;
    }
}


/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */
bool play()
{
    // Insert your code here
    std::cout << "\n";
    while(true)
    {
        srand(time(NULL));
        int u = 0;
        int cpu = 1 + (std::rand() % 3);
        cout << "1.Rock " << "2.Paper " << "3.Scissors "
        << "Choose your play: ";
        cin >> u;
        if(u < 1 || u > 3)
        {
            cout << "Invalid choice\n";
            continue;
        }
        std::cout << "You " << u << " & CPU " << cpu << "\n";
        if (u == cpu)  {
            std::cout << "It's a draw so go again\n";
            return play();
        } else {
            return beats(u, cpu);
        }
    }
}


/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3()
{
    // Insert your code here
    int w=0;
    int l=0;
    for (int i=1; i<=3; i++) {
        bool game = play();
        w = game ? w+1 : w;
        l = game==false ? l+1 : l;
        std::cout << "Your Score is " << w << " : " << l << "\n";
        if (w>1) return true;
        if (l>1) return false;
    }
    return false;
}


/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5()
{
    // Insert your code here
    int w=0;
    int l=0;
    for (int i=1; i<=5; i++) {
        bool game = play();
        w = game ? w+1 : w;
        l = game==false ? l+1 : l;
        std::cout << "Your Score is " << w << " : " << l << "\n";
        if (w>2) return true;
        if (l>2) return false;
    }
    return false;
}


/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char* gameModeToString(int mode)
{
    switch(mode){
        case 1:
            return "Single";
        case 2:
            return "Best of Three";
        case 3:
            return "Best of Five";
        default:
            return "invalid";
    }
}


int main()
{
    // Initialize random seed
    srand(time(nullptr));

    int mode = 0;
    while(true)
    {
        cout << "Choose a game mode: \n"
             << "1: " << gameModeToString(1) << "\n"
             << "2: " << gameModeToString(2) << "\n"
             << "3: " << gameModeToString(3) << "\n"
             << "0: exit\n";
        cout << "Your choice: ";
        cin >> mode;
        if(mode == 0) return 0;
        if(mode < 1 || mode > 3)
        {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }

    bool won = false;
    switch(mode)
    {
        case 1:
            won = play();
            break;
        case 2:
            won = bestOf3();
            break;
        case 3:
            won = bestOf5();
            break;
        default:
            // unreachable code
            return -1;
    }

    if(won)
    {
        cout << "Congratulations! You won the game!\n";
    }
    else
    {
        cout << "Unfortunate! You lost the game.\n";
    }
    return 0;
}