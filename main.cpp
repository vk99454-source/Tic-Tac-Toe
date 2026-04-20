#include <iostream>

#include "src/tictactoe.hpp"
using namespace std;
int main() {
    bool playAgain = true;
    string answer;
    string mode;
    while (playAgain) {
        while (true) {
            cout << "Choose a game mode:" << endl;
            cout << "1. Human vs Human" << endl;
            cout << "2. Human vs Computer" << endl;
            cout << "3. Computer vs Human" << endl;
            cout << "Enter your choice: ";
            getline(cin,mode);
            if (mode == "1" || mode == "2" || mode == "3") {
                break;
            }
            else {
                cout << "This is not a valid entry!" << endl;
            }
        }
        tictactoe game;
        string input;
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        game.printBoard();
        while (true) {
            if ((mode == "2" && game.getPlayer() == 'O') || (mode == "3" && game.getPlayer() == 'X')) {
                for (int i = 1; i <= 9; i++) {
                    string computerMove = to_string(i);
                    if (game.validMove(computerMove) == true) {
                        cout << "Computer chooses " << i << endl;
                        game.makeMove(i);
                        game.printBoard();
                        break;
                    }
                }
                if (game.checkWin() == true) {
                    cout << "Player " << game.getPlayer() << " wins!" << endl;
                    break;
                }
                if (game.checkDraw() == true) {
                    cout << "It's a draw!" << endl;
                    break;
                }
                game.switchPlayer();
                continue;
            }
            cout <<"What is your move? ";
            getline(cin,input);
            if (game.validMove(input) == false) {
                cout << endl;
                cout << "That is not a valid move! Try again." << endl << endl;
                game.printBoard();
                continue;
            }
            int position = input[0] - '0';
            game.makeMove(position);
            game.printBoard();
            if (game.checkWin() == true) {
                cout << "Player " << game.getPlayer() << " wins!" << endl;
                break;
            }
            if (game.checkDraw() == true) {
                cout << "It's a draw!" << endl;
                break;
            }
            game.switchPlayer();
        }
        while (true) {
            cout << "Would you like to play again (yes/no)? ";
            getline(cin, answer);
            if (answer == "yes" || answer == "y") {
                break;
            }
            else if (answer == "no" || answer == "n") {
                playAgain = false;
                break;
            }
            else {
                cout << "That is not a valid entry!" << endl;
            }
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}