#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <stdexcept>
#include "../headers/game.h"

const Disc redDisc = Disc::RED;
const Disc yellowDisc = Disc::YELLOW;

TEST_CASE("ACCESSOR TEST CASES", "[game]") {
    Game g = Game();

    REQUIRE(g.getCurrentPlayer() == redDisc);
    g.makeMove(1);
    REQUIRE(g.getCurrentPlayer() == yellowDisc);
    g.makeMove(3);
    REQUIRE(g.getCurrentPlayer() == redDisc);
    g.makeMove(4);
    REQUIRE(g.getCurrentPlayer() == yellowDisc);
    g.makeMove(7);
    REQUIRE(g.getCurrentPlayer() == redDisc);
}

TEST_CASE("MAKE MOVE TESTCASE #1: VALID GAME MOVES", "[game]") {
    Game g = Game();

    REQUIRE(g.getCurrentPlayer() == redDisc);
    REQUIRE(g.makeMove(1));
    REQUIRE(g.getCurrentPlayer() == yellowDisc);
    REQUIRE(g.makeMove(3));
    REQUIRE(g.getCurrentPlayer() == redDisc);
    REQUIRE(g.makeMove(4));
    REQUIRE(g.getCurrentPlayer() == yellowDisc);
    REQUIRE(g.makeMove(7));
    REQUIRE(g.getCurrentPlayer() == redDisc);
}

TEST_CASE("MAKE MOVE TESTCASE #2: INVALID GAME MOVES, COLUMN RANGE", "[game]") {
    Game g = Game();
    Disc startingPlayer = g.getCurrentPlayer();

    for(int i = -2; i < 1; i++) {
         REQUIRE(!g.makeMove(i));
         REQUIRE(g.getCurrentPlayer() == startingPlayer);
    }
       
    for(int i = 8; i <= 11; i++) {
        REQUIRE(!g.makeMove(i));
        REQUIRE(g.getCurrentPlayer() == startingPlayer);
    }
        
}

TEST_CASE("MAKE MOVE TESTCASE #3: INVALID GAME MOVES, COLUMN FULL", "[game]") {
    Game g = Game();
    int testColumn1 = 1;
    int testColumn2 = 7;
    int testColumn3 = 4;

    for(int i = 0; i < 6; i++)
        REQUIRE(g.makeMove(testColumn1));
    REQUIRE(!g.makeMove(testColumn1));

    for(int i = 0; i < 6; i++)
        REQUIRE(g.makeMove(testColumn2));
    REQUIRE(!g.makeMove(testColumn2));

     for(int i = 0; i < 6; i++)
        REQUIRE(g.makeMove(testColumn3));
    REQUIRE(!g.makeMove(testColumn3));
}

TEST_CASE("IS OVER TESTCASE #1: VERTICAL MATCH", "[game]") {
    Game g = Game();
    int testColumn1 = 1;
    int testColumn2 = 2;

    for(int i = 0; i < 3; i++) {
        REQUIRE(g.makeMove(testColumn1));
        REQUIRE(!g.isOver());
        REQUIRE(g.makeMove(testColumn2));
        REQUIRE(!g.isOver());
    }

    REQUIRE(g.makeMove(testColumn1));
    REQUIRE(g.isOver());
}

TEST_CASE("IS OVER TESTCASE #2: HORIZONTAL MATCH", "[game]") {
    Game g = Game();

    for(int i = 0; i < 3; i++) {
        REQUIRE(g.makeMove(i + 1));
        REQUIRE(!g.isOver());
        REQUIRE(g.makeMove(i + 1));
        REQUIRE(!g.isOver());
    }

    REQUIRE(g.makeMove(4));
    REQUIRE(g.isOver());
}

TEST_CASE("IS OVER TESTCASE #3: DIAGONAL LDUR MATCH", "[game]") {
    Game g = Game();

    REQUIRE(g.makeMove(1));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(2));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(2));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(7));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(3));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(3));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(3));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(g.isOver());
}

TEST_CASE("IS OVER TESTCASE #3: DIAGONAL LUDR MATCH", "[game]") {
    Game g = Game();

    REQUIRE(g.makeMove(1));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(7));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(6));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(6));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(1));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(5));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(5));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(5));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(!g.isOver());
    REQUIRE(g.makeMove(4));
    REQUIRE(g.isOver());
}