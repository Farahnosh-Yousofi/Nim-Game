# Nim-Game
# Nim Game (C++) 🎮

A C++ implementation of the classic Nim game where a human player competes against a computer using an optimal (smart) strategy. This project demonstrates object-oriented programming, game logic design, and input validation.

## Overview

Nim is a mathematical game where two players take turns removing marbles from a pile. Each player must take at least one but at most half of the marbles. The player who is forced to take the last marble **loses**.

This program allows a user to play against the computer, which follows a **smart winning strategy** based on game theory.

According to the assignment description, the computer aims to reduce the pile to sizes of the form **2ⁿ − 1 (1, 3, 7, 15, …)** whenever possible :contentReference[oaicite:0]{index=0}.

## Features

- Human vs Computer gameplay
- Smart computer strategy (optimal moves)
- Randomized starting player
- Random initial pile size (10–250 marbles)
- Input validation for user moves
- Visual display of marbles in the pile
- Object-oriented design using a custom `Nim` class

## Technologies Used

- C++
- Standard Libraries:
  - `<iostream>`
  - `<cstdlib>`
  - `<ctime>`
  - `<cmath>`
  - `<iomanip>`

## Project Structure
Nim-Game/
│── Nim.h # Class definition
│── Nim.cpp # Class implementation
│── Project2.cpp # Main program (game logic)

## How It Works

1. A random number of marbles (between 10 and 250) is generated.
2. The program randomly decides who goes first.
3. Players take turns:
   - Must take **at least 1 and at most half** of the marbles
4. The computer uses a smart strategy:
   - If possible, leaves the pile as a **2ⁿ − 1 number**
   - Otherwise, makes a random valid move
5. The game continues until only one marble remains.
6. The player forced to take the last marble **loses**.

## Key Class

```cpp
class Nim
Includes:
computer_play() → Implements smart strategy
player_play() → Handles user input and validation
print() → Displays current pile
Example Gameplay
Welcome to the game of Nim
Player: Marwa
Computer goes first

There are 45 marbles in the pile
Computer takes 14 marbles

Your turn:
You take: 5

...

Learning Outcomes
Object-Oriented Programming (OOP) in C++
Designing game logic and rules
Implementing algorithms (optimal strategy)
Input validation and error handling
Working with randomness in programs
Author
Farahnosh Yousofi
