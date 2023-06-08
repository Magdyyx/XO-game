// Class definition for XO_Board class
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

Board::Board()
{
    cout << "Enter the size of the board: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = ' ';
        }
    }
    for (int j = 1, i = 0; j <= n - 2; ++j)
    {
        board[i][j] = 'A';
    }
    for (int j = 1, i = 0; j <= n - 2; ++j)
    {
        board[j][i] = 'B';
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Board::update_board1(int xold, int yold, int xnew, int ynew, char mark)
{


    n_moves++;
    // Only update if move is valid

    if (xnew >= 0 && xnew < n && ynew >= 0 && ynew < n && xold >= 0 && xold < n && yold >= 0 && yold < n && board[xold][yold] == mark)
    {
        {
            // validating if the new cell is adjacent to the previous cell or not

            if (xnew == xold + 1 && ynew == yold && board[xnew][ynew] != 'A' && board[xnew][ynew] != 'B')
            {
                board[xnew][ynew] = mark;
                board[xold][yold] = ' ';
                return true;
            }
            else if (xnew == xold + 2 && ynew == yold && board[xnew - 1][ynew] == 'B')
            {
                board[xnew][ynew] = mark;
                board[xold][yold] = ' ';
                return true;
            }
            else
            {
                cout << "Invalid move1" << endl;
                return false;
            }
        }
    }
    else
    {
        cout << "Invalid move 2" << endl;
        return false;
    }
}

bool Board::update_board2(int xold, int yold, int xnew, int ynew, char mark)
{
    n_moves++;

    // Only update if move is valid
    if (xnew >= 0 && xnew < n && ynew >= 0 && ynew < n && xold >= 0 && xold < n && yold >= 0 && yold < n && board[xold][yold] == mark)
    {
        {
            // validating if the new cell is adjacent to the previous cell or not

            if (xnew == xold && ynew == yold + 1 && board[xnew][ynew] != 'A' && board[xnew][ynew] != 'B')
            {
                board[xnew][ynew] = mark;
                board[xold][yold] = ' ';
                return true;
            }
            else if (xnew == xold && ynew == yold + 2 && board[xnew][ynew - 1] == 'A')
            {
                board[xnew][ynew] = mark;
                board[xold][yold] = ' ';
                return true;
            }
            else
            {
                cout << "Invalid move" << endl;
                return false;
            }
        }
    }
    else
    {
        cout << "Invalid move" << endl;
        return false;
    }
}
// Display the board and the pieces on it

void Board::display_board()
{

    board[0][0] = 'X';
    board[n - 1][0] = 'X';
    board[0][n - 1] = 'X';
    board[n - 1][n - 1] = 'X';

    for (int i = 0; i < n; i++)
    {
        cout << "\n| ";
        for (int j = 0; j < n; j++)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Board::is_winner()
{
    bool player1 = false;
    bool player2 = false;
    int ct = 0;
    int ct1 = 0;
    int j = n - 1;
    for (int i = 1; i <= n - 2; ++i)
    {
        if (board[i][j] == 'B')
        {
            ct++;
        }
        if (ct == n - 2)
        {
            player2 = true;
        }
    }
    for (int i = 1; i <= n - 2; ++i)
    {
        if (board[j][i] == 'A')
        {
            ct1++;
        }
        if (ct1 == n - 2)
        {
            player1 = true;
        }
    }
    if (player1 || player2)
        return true;
    else
        return false;
}

int Board::get_n()
{
    return n;
}

vector<int> Board::get_newpos(int xold, int yold, char symbol)
{
    if ((symbol != board[xold][yold]) || ((xold + yold) > (get_n() * 2 - 2)))
    {
        return {-1, -1};
    }
    if (symbol == 'B')
    {
        if (yold == (get_n() - 1))
        {
            return {-1, -1};
        }
        if (board[xold][yold + 1] == ' ')
        {
            return {xold, yold + 1};
        }
        if (board[xold][yold + 1] == 'A' && board[xold][yold + 2] == ' ')
        {
            return {xold, yold + 2};
        }
    }
    if (board[xold][yold] == 'A')
    {
        if (xold == (get_n() - 1))
        {
            return {-1, -1};
        }
        if (board[xold + 1][yold] == ' ')
        {
            return {xold + 1, yold};
        }
        if (board[xold + 1][yold] == 'B' && board[xold + 2][yold] == ' ')
        {
            return {xold + 2, yold};
        }
    }
    return {-1, -1};
}

char *Board::operator[](int k)
{
    return board[k];
}

void Board::modify_board(int xold, int yold, int xnew, int ynew, char mark) {
    board[xold][yold]=' ';
    board[xnew][ynew]=mark;
}

