/*
 * Course: CS215-010
 * Project: Project 2
 * File: Nim.ccp
 * Purpose: it defines the class named Nim
 * Author: Farahnosh Yousofi
 */

 
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Nim.h"

using namespace std;


//default constructor
Nim::Nim()
{
	pileSize = 0;
}

//constructor
Nim::Nim(int iniSize)
{
	pileSize = iniSize;
}

//set the current size of the pile 
void Nim::setPileSize(int size)
{
	pileSize = size;
}

//get how many marbles on the pile
int Nim::getPileSize() const
{
	return pileSize;
}

//if it is computer's turn to play
//computer takes a legal move, and takes off some marbles
//computer alwasys takes "perfect stategy" trying to win

/*
* It represents the legal move when it is the computer's turn to play
* The computer takes “smart strategy” trying to win the game:
*	(1)if the current pile size is not a Power-of-Two-minus-One, it takes
*	 off enough marbles to make the remaining a Power-of-Two-minus-One;
*	(2)otherwise, it randomly takes at least one but at most half
* (Note that the private data member, pileSize, will be modified)
*@return: void function
*/
void Nim::computer_play()
{
	int pickMarble = 0;
	int M_MaxTake = pileSize / 2;

	bool PowerOfTwo;
	int power_of_two = pileSize + 1;

	
	

		PowerOfTwo = (ceil(log2(power_of_two)) == floor(log2(power_of_two)));

		if (PowerOfTwo)
		{
			pickMarble = rand() % M_MaxTake + 1; //produce a random number to get from pile
		}
		else
		{
			while (!PowerOfTwo)
			{
				pickMarble++;
				PowerOfTwo = (ceil(log2(pileSize - pickMarble + 1)) == floor(log2(pileSize - pickMarble + 1)));

			}

		}
	
		
	cout << "The computer take " << pickMarble << " Marbles" << endl << endl;
	pileSize = pileSize - pickMarble; //removes the picked marbles from pile


}

/*
* It represents the legal move when it is the user's turn to play the game * (it should repeatedly ask the user to enter how many marbles to take
* until the user makes a legal move.) * (Note that the private data member, pileSize, will be modified)
*@return: void function
*/
void Nim:: player_play()
{
	int pickMarble;
	int M_MaxTake = pileSize / 2;
	bool invalid = true;

	// this do while is for checking the user input whether it is valid or not
	do 
	{

		cout << "Your turn to play ... you may take " << 1 << " to " << M_MaxTake << " marbles." << endl;
		cout << "You take:";
		cin >> pickMarble;
	
	if (cin.fail())
	{
		cout << "Invalid! Please try again..." << endl;
		cin.clear();
		cout << endl;
	}
	else if (pickMarble<1 || pickMarble>M_MaxTake)
	{
		cout << "Ooops, you picked too many or not enough." << endl;
		cout << "Please try again... " << endl;
		cout << endl;
	}
	else 
	{
		cout << "You will take " << pickMarble << " Marbles." << endl << endl;
		invalid = !invalid;
	}
		cin.ignore(256, '\n');
	} while (invalid);

	pileSize = pileSize - pickMarble; //removes the picked marbles from pile
}

//display the current marbles on the pile
void Nim::print() const
{
	cout << "There are " << getPileSize() << " marbles in the pile." << endl;
	for (int M_count = 0; M_count < getPileSize(); M_count++)
	{
		cout << setw(WIDTH) << MARBLE << endl;
	}
}

