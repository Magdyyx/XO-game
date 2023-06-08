// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include <vector>
#include "Classes.hpp"
using namespace std;

void GameManager::run()
{
    cout << "Welcome to the game of trees: " << endl;
    cout << "Choose between 1 and 2: " << endl;
    cout << "1- Player vs Player" << endl;
    cout << "2- Player vs Computer" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        player_vs_player();
        break;
    case 2:
        player_vs_computer();
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}

void GameManager::player_vs_player()
{
    Board x_o;
    int xold, yold, xnew, ynew;
    Player players[2] = {Player(1, 'A'), Player(2, 'B')};
    x_o.display_board();
    while (true)
    {
        for (int i : {0, 1})
        {
            cout << "Player: " << players[i].get_symbol() << endl;
            cout << "Possible Moves: " << endl;
            for (auto l : players[i].get_valid_moves(x_o))
            {
                cout << l[0] << ' ' << l[1] << " -> " << l[2] << ' ' << l[3] << endl;
            }
            if (i == 0)
            {
                cout << "Player 1's turn" << endl;
                players[i].get_move(xold, yold, xnew, ynew);
                while (!x_o.update_board1(xold, yold, xnew, ynew, 'A'))
                {

                    players[i].get_move(xold, yold, xnew, ynew);
                }
            }
            else
            {
                cout << "Player 2's turn" << endl;
                players[i].get_move(xold, yold, xnew, ynew);
                while (!x_o.update_board2(xold, yold, xnew, ynew, 'B'))
                {
                    players[i].get_move(xold, yold, xnew, ynew);
                }
            }

            x_o.display_board();

            if (x_o.is_winner())
            {
                cout << players[i].to_string() << " wins\n";
                return;
            }
        }
    }
}

void GameManager::player_vs_computer()
{
    Board x_o;
    int xold, yold, xnew, ynew;
    ComputerPlayer computer(1, 'A');
    Player human(2, 'B');

    x_o.display_board();
    while (true)
    {
        for (int i : {0, 1})
        {


            if (i == 0)
            {
                cout << "Player 1's turn" << endl;
               vector<int>el= computer.getMove(x_o,human);
               xold=el[0];
               yold=el[1];
               xnew=el[2];
               ynew=el[3];

                cout << "Possible Moves: " << endl;
                for (auto l : computer.get_valid_moves(x_o))
                {
                    cout << l[0] << ' ' << l[1] << " -> " << l[2] << ' ' << l[3] << endl;
                }


                if (computer.get_valid_moves(x_o).size()==0){
                    cout<<"There is no valid move for you. Your turn passes to the other player"<<endl;
                    continue;
                }
                while (!x_o.update_board1(xold, yold, xnew, ynew, 'A'))
                {
                    cout<<xold<<" "<<yold<<" "<<xnew<<" "<<ynew<<endl;

                    computer.getMove(x_o,human);
                }
            }
            else
            {
                cout << "Possible Moves: " << endl;
                for (auto l : human.get_valid_moves(x_o))
                {
                    cout << l[0] << ' ' << l[1] << " -> " << l[2] << ' ' << l[3] << endl;
                }

                cout << "Player 2's turn" << endl;

                human.get_move(xold, yold, xnew, ynew);




                if (human.get_valid_moves(x_o).size()==0){
                    cout<<"There is no valid move for you. Your turn passes to the other player"<<endl;
                    continue;
                }
                while (!x_o.update_board2(xold, yold, xnew, ynew, 'B'))
                {
                    human.get_move(xold, yold, xnew, ynew);
                }
            }

            x_o.display_board();
            if (x_o.is_winner())
            {
                cout << human.to_string() << " wins\n";
                return;
            }
        }
    }
}
