/*
 * Course: CS215-010
 * Project: Project 2
 * File: Nim.h
 * Purpose: it declares the class named Nim
 *
 */
#ifndef NIM_H
#define NIM_H

const int PILE_MAX = 250;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose




class Nim
{
public:
	//default constructor
	Nim();

	//constructor
	Nim(int iniSize);

	//set the current size of the pile 
	void setPileSize(int size);

	//get how many marbles on the pile
	int getPileSize() const;

	//if it is computer's turn to play
	//computer takes a legal move, and takes off some marbles
	//computer alwasys takes "perfect stategy" trying to win
	void computer_play();

	//if it is human player's (the user's) turn to play
	/*
	 * It represents the legal move when it is the user's turn to play the game
	 * (it should repeatedly ask the user to enter how many marbles to take
	 * until the user makes a legal move.)
	 * (Note that the private data member, pileSize, will be modified)
	 *@return: void function
	 */
	void player_play();

	//display the current marbles on the pile
	void print() const;

private:
	int pileSize;	// represents how many marbles on the 
};
#endif	/* NIM_H */

