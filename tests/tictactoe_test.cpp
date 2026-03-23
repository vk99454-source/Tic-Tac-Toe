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
