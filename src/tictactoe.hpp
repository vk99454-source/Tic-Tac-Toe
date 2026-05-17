#include <string>
#include <vector>
using namespace std;

class tictactoe {
    public:
    tictactoe();
    void printBoard() const;
    bool validMove(string input) const;
    void makeMove(int position);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    void resetGame();
    char getPlayer() const;
    void enableTrap ();
    void disableTrap ();
    bool isTrap(int position) const;
    int firstAvailableSpot() const;
private:
    vector<string> board;
    char currentPlayer;
    bool trapEnabled;
    int trapPosition;
};