// Class definition for XO_Player class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "Classes.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol)
{
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player(int order, char symbol)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move(int &xold, int &yold, int &xnew, int &ynew)
{
    cout << "Please enter your move x and y (0 to 2) separated by spaces" << endl;
    cout << "Enter from which cell you want to move from: " << endl;
    cin >> xold >> yold;
    cout << "Enter to which cell you want to move to: " << endl;
    cin >> xnew >> ynew;
}

// Give player info as a string
string Player::to_string()
{
    return "Player: " + name;
}

// Get symbol used by player
char Player::get_symbol()
{
    return symbol;
}

vector<vector<int>> Player::get_valid_moves(Board &brd)
{
    vector<vector<int>> moves;
    //    if (symbol == 'A') {
    for (int i = 0; i < brd.get_n(); i++)
    {
        for (int j = 0; j < brd.get_n(); j++)
        {
            if (brd[i][j] == symbol)
            {
                vector<int> v = brd.get_newpos(i, j, symbol);
                if (v[0] > -1)
                {
                    moves.push_back({i, j, v[0], v[1]});
                }
            }
        }
    }
    return moves;
}

