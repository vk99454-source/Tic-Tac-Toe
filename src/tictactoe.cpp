#include "tictactoe.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

tictactoe::tictactoe() {
board.push_back("1");
    board.push_back("2");
    board.push_back("3");
    board.push_back("4");
    board.push_back("5");
    board.push_back("6");
    board.push_back("7");
    board.push_back("8");
    board.push_back("9");
    currentPlayer = 'X';
    trapEnabled = false;
    trapPosition = -1;
}
void tictactoe::printBoard() const {
cout << endl;
    cout << "    " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "  -----+-----+-----" << endl;
    cout << "    " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "  -----+-----+-----" << endl;
    cout << "    " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << endl;
}
bool tictactoe::validMove(string input) const {
if (input.length() !=1) {
    return false;
}
    if (input[0] < '1' || input[0] > '9') {
        return false;
    }
    int position = input[0] - '0';
    if (board[position - 1] == "X" || board[position - 1] == "O") {
        return false;
    }
    return true;
}
void tictactoe::makeMove(int position) {
if (currentPlayer == 'X') {
    board[position - 1] = "X";
}
    else {
        board[position - 1] = "O";
    }
}
bool tictactoe::checkWin() const {
    if (board[0] == board [1] && board [1] == board[2]) {
        return true;
    }
    if (board[3] == board [4] && board [4] == board[5]) {
        return true;
    }
    if (board[6] == board [7] && board [7] == board[8]) {
        return true;
    }
    if (board[0] == board [3] && board [3] == board[6]) {
        return true;
    }
    if (board[1] == board [4] && board [4] == board[7]) {
        return true;
    }
    if (board[2] == board [5] && board [5] == board[8]) {
        return true;
    }
    if (board[0] == board [4] && board [4] == board[8]) {
        return true;
    }
    if (board[2] == board [4] && board [4] == board[6]) {
        return true;
    }
    return false;
}
bool tictactoe::checkDraw() const {
for (int i = 0; i < board.size(); i++) {
    if (trapEnabled == true && i + 1 == trapPosition) {
        continue;
    }
    if (board[i] != "X" && board[i] != "O") {
        return false;
    }
}
    return true;
}
void tictactoe::switchPlayer() {
if (currentPlayer == 'X') {
    currentPlayer = 'O';
}
    else {
        currentPlayer = 'X';
    }
}
void tictactoe::resetGame() {
    board.clear();
board.push_back("1");
    board.push_back("2");
    board.push_back("3");
    board.push_back("4");
    board.push_back("5");
    board.push_back("6");
    board.push_back("7");
    board.push_back("8");
    board.push_back("9");
    currentPlayer = 'X';
    trapEnabled = false;
    trapPosition = -1;
}
char tictactoe::getPlayer() const {
return currentPlayer;
}
void tictactoe::enableTrap() {
    trapEnabled = true;
    trapPosition = rand() % 9 + 1;
}
void tictactoe::disableTrap() {
    trapEnabled = false;
    trapPosition = -1;
}
bool tictactoe::isTrap(int position) const {
    if (trapEnabled == true && position == trapPosition) {
        return true;
    }
    return false;
}
int tictactoe::firstAvailableSpot() const {
    for (int i = 0; i < board.size(); i++) {
        if (board[i] != "X" && board[i] != "O") {
            return i + 1;
        }
    }

    return -1;
}