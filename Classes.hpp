// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef _XO_CLASSES_H
#define _XO_CLASSES_H
#include <vector>
using namespace std;

// This class represents a 3 x 3 board
// used in X_O game

class Board {
protected:
    int n; // Board size

   int  n_moves = 0;

public:
    // Constructor
    char board[100][100] = {{0}};
    Board();
    vector<int> get_newpos(int xold, int yold,char symbol);
   // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   bool update_board1 (int xold, int yold,int xnew, int ynew, char mark);
   bool update_board2 (int xold, int yold,int xnew, int ynew, char mark);
   void modify_board(int xold, int yold, int xnew, int ynew, char mark);
    int get_n();
    char* operator[] (int k);
    // Returns true if there is any winner
   // either X or O
   // Written in a complex way. DO NOT DO LIKE THIS.
   bool is_winner();
   // Return true if 9 moves are done and no winner
   bool is_draw();
   // Display the board and the pieces on it
   void display_board();
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
    protected:
        string name;
        char symbol;
    public:
        // Two constructors to initiate player
        // Give player a symbol to use in playing
        // It can be X or O or others
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2
        vector<vector<int>> get_valid_moves(Board&);
        Player (char symbol); // Needed for computer players
        Player (int order, char symbol);
        // Get desired move: x y (each between 0 and 2)
        // Virtual (can change for other player types)
        virtual void get_move(int& xold, int& yold,int& xnew, int& ynew);
        // Give player info as a string
        string to_string();
        // Get symbol used by player
        char get_symbol();
};

///////////////////////////////////////////
// This class represents the engine that runs
// X-O games and gives players turns, sees if
// either of them won or it is draw.
// It has one method to start and run the game.
class GameManager {
    public:
        void run();
        void player_vs_player();
        void player_vs_computer();
        // This method creates board and players
        // It displays board
        // While True
        //   For each player
        //      It takes a valid move as x, y pair (between 0 - 2)
        //      It updates board and displays otit
        //      If winner, declare so and end
        //      If draw, declare so and end

};

class ComputerPlayer : public Player
{
    int solveBoard(Board b, int depth, int alpha, int beta, Player &otherPlayer, bool computersTurn, int count);
public:
    ComputerPlayer(int order, char symbol);
    vector<int> getMove(Board &b, Player &otherPlayer);



    };
#endif
