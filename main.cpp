#include <iostream>

#include "src/tictactoe.hpp"
using namespace std;
int main() {
    bool playAgain = true;
    string answer;
    while (playAgain) {
        tictactoe game;
        string input;
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        game.printBoard();
        while (true) {
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
            if (answer == "yes") {
                break;
            }
            else if (answer == "no") {
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