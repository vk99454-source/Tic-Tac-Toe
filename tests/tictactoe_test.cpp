#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE("game starts with player X") {
    tictactoe game;
    REQUIRE(game.getPlayer() == 'X');
}
TEST_CASE("valid move is accepted") {
    tictactoe game;
    REQUIRE(game.validMove("1") == true);
}
TEST_CASE("taken spot is invalid") {
    tictactoe game;
    game.makeMove(1);
    REQUIRE(game.validMove("1") == false);
}
TEST_CASE("switch player works") {
    tictactoe game;
    game.switchPlayer();
    REQUIRE(game.getPlayer() == 'O');
}
TEST_CASE("reset game puts player back to X") {
    tictactoe game;
    game.switchPlayer();
    game.resetGame();
    REQUIRE(game.getPlayer() == 'X');
}
TEST_CASE("reset game clears taken spots") {
    tictactoe game;
    game.makeMove(1);
    game.resetGame();
    REQUIRE(game.validMove("1") == true);
}
TEST_CASE("trap is off by default") {
    tictactoe game;
    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.isTrap(i) == false);
    }
}
TEST_CASE("enableTrap creates exactly one trap") {
    tictactoe game;
    game.enableTrap();
    int trapCount = 0;
    for (int i = 1; i <= 9; i++) {
        if (game.isTrap(i) == true) {
            trapCount++;
        }
    }
    REQUIRE(trapCount == 1);
}
TEST_CASE("disableTrap turns trap off") {
    tictactoe game;
    game.enableTrap();
    game.disableTrap();
    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.isTrap(i) == false);
    }
}
TEST_CASE("resetGame clears the trap") {
    tictactoe game;
    game.enableTrap();
    game.resetGame();
    for (int i = 1; i <= 9; i++) {
        REQUIRE(game.isTrap(i) == false);
    }
}
TEST_CASE("draw works when trap cell is left unmarked") {
    tictactoe game;
    game.enableTrap();
    for (int i = 1; i <= 9; i++) {
        if (game.isTrap(i) == false) {
            game.makeMove(i);
        }
    }
    REQUIRE(game.checkDraw() == true);
}
TEST_CASE("computer chooses first spot on empty board") {
    tictactoe game;
    REQUIRE(game.firstAvailableSpot() == 1);
}

TEST_CASE("computer skips taken spot and chooses next open one") {
    tictactoe game;
    game.makeMove(1);
    REQUIRE(game.firstAvailableSpot() == 2);
}

TEST_CASE("computer chooses next available spot after multiple moves") {
    tictactoe game;
    game.makeMove(1);
    game.switchPlayer();
    game.makeMove(2);
    game.switchPlayer();
    game.makeMove(3);

    REQUIRE(game.firstAvailableSpot() == 4);
}

TEST_CASE("computer returns -1 when board is full") {
    tictactoe game;

    game.makeMove(1);
    game.switchPlayer();
    game.makeMove(2);
    game.switchPlayer();
    game.makeMove(3);
    game.switchPlayer();
    game.makeMove(4);
    game.switchPlayer();
    game.makeMove(5);
    game.switchPlayer();
    game.makeMove(6);
    game.switchPlayer();
    game.makeMove(7);
    game.switchPlayer();
    game.makeMove(8);
    game.switchPlayer();
    game.makeMove(9);

    REQUIRE(game.firstAvailableSpot() == -1);
}