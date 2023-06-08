//
// Created by ahmed on 12/15/2022.
//
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "Classes.hpp"
using namespace std;

ComputerPlayer::ComputerPlayer(int order, char symbol) : Player(1, symbol) {

}

int ComputerPlayer::solveBoard(Board b, int depth, int alpha, int beta, Player &otherPlayer, bool computersTurn, int count) {

    int eval;
    vector<vector<int>> v;
    if (b.is_winner() || !depth) {
        if (computersTurn) {
            return 1000;
        } else {
            return -1000;
        }
    }
    if (computersTurn) {
        int minimum = INT_MAX;
        v = get_valid_moves(b);
        sort(v.begin(), v.end(), [](vector<int> pos1, vector<int> pos2) {
            return ((pos1[2] - pos1[0]) + (pos1[3] - pos1[1])) > ((pos2[2] - pos2[0]) + (pos2[3] - pos2[1]));
        });
        for (auto el: v) {
            b.modify_board(el[0], el[1], el[2], el[3],'A');
            eval = solveBoard(b, depth - 1, alpha, beta, otherPlayer, false, count);
            minimum = min(minimum, eval);
            b.modify_board(el[2], el[3], el[0], el[1],'A');
            beta = min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return minimum;
    } else {
        int maximum = INT_MIN;
        v = otherPlayer.get_valid_moves(b);
        sort(v.begin(), v.end(), [](vector<int> pos1, vector<int> pos2) {
            return ((pos1[2] - pos1[0]) + (pos1[3] - pos1[1])) > ((pos2[2] - pos2[0]) + (pos2[3] - pos2[1]));
        });
        for (auto el: v) {
            b.modify_board(el[0], el[1], el[2], el[3],'A');
            eval = solveBoard(b, depth - 1, alpha, beta, otherPlayer, true, count);
            maximum = max(maximum, eval);
            b.modify_board(el[2], el[3], el[0], el[1],'A');
            alpha = max(alpha, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return maximum;
    }

}



vector<int> ComputerPlayer::getMove(Board &b, Player &otherPlayer) {

    int score = INT_MAX;
    int bestScore = INT_MAX;
    vector<int> computerMove{-1, -1};
    for (auto el : get_valid_moves(b))
    {
        b.modify_board(el[0], el[1], el[2], el[3],'A');
        score = solveBoard(b, 1000, INT_MIN, INT_MAX, otherPlayer, false, 0);
        b.modify_board(el[2], el[3], el[0], el[1],'A');
        if (score < bestScore)
        {
            bestScore = score;
            computerMove = {el[0], el[1],el[2],el[3]};
        }
    }
    return computerMove;
}

