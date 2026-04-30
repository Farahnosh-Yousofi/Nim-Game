/*
 *Course: CS215 - 010
 *Project: Project 2
 *Purpose: It demonstrates the game of Nim played between two computer players
 *         In combinatorial game theory, a two-player deterministic perfect information turn-based game
 *         is a first-player-win if with perfect play the first player to move can always force a win.
 *         This program also shows that the game of Nim is a "CONDITIONAL first-player-win" game using two computer players.
 *Author: (Farahnosh Yousofi)
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;

int main()
{
    
    string User_Name;
    
    int seed = static_cast<int>(time(0));
    srand(seed);
    // Generate the initial size of pile (of marbles)
    // at the range of [PILE_MIN, PILE_MAX]
    int pileSize = PILE_MIN + rand() % (PILE_MAX - PILE_MIN + 1);

    cout << "Welcome to the game of Nim (for two players)" << endl;
    cout << "Please input your name: ";
    cin >> User_Name;
    cout << endl;
    
    int Player_Turn;
    Player_Turn = rand() % 2 + 0;

    // create a Nim object with initial pile size = pileSize
    Nim NimGame(pileSize);
   
    cout << endl;
    cout << "*******************************************************" << endl;
    cout << "*                   The game of Nim                   *" << endl;
    cout << "*      Players alternate taking at least one but at   *" << endl;
    cout << "*      most half of the marbles in the pile.          *" << endl;
    cout << "*      The player who takes the last marble loses.    *" << endl;
    cout << "*      It is written by Farahnosh Yousofi             *" << endl;
    cout << "*      I hope you beat the computer : )               *" << endl;
    cout << "*      No matter what, have a great day!              *" << endl;
    cout << "*******************************************************" << endl<< endl;
    cout << endl;

    //computer willplay first 
    if (Player_Turn == 1)
    {
        cout << "The Computer will play first." << endl;
        cout << "Then followed by the " << User_Name << endl<<endl;
    }
    else
    {
        cout << User_Name << " will play first." << endl;
        cout << "Then followed by the Computer." << endl<<endl;
    }

    bool PlayerTurn = (Player_Turn == 0);
    

    while (NimGame.getPileSize() > 1)
    {
        NimGame.print();
        if (PlayerTurn) //it is User's turn to play
        {
            cout << "It is " << User_Name <<  "'s turn:" << endl;
            NimGame.player_play();
        }
        else   // it is SUPER's turn to play
        {
            cout << "It is Computer's turn:" << endl;
            NimGame.computer_play();
        }

        PlayerTurn = !PlayerTurn;
    }

    //check the which one has to take the last marble to lose the game
    if (PlayerTurn)  // User's turn (for this program, this will never happen as long as PIKE is the first player!
    {
        cout << "You must take the last marble.You lose!" << endl;

    }
    else   // SUPER's turn
    {
        cout << "Computer must take the last marble. You win!" << endl;
    }
    return 0;
}