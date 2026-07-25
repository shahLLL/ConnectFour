#include <iostream>
#include <string>
#include <limits>
#include "headers/board.h"
#include "headers/game.h"

using namespace std;

// This function prints the Game Into Message
void displayIntro() {
    cout << ANSI_YELLOW << "WELCOME TO CPP CONNECT-4" << ANSI_END << endl;
    cout << ANSI_RED << "GOOD LUCK!" << ANSI_END << endl;
    Board b = Board();
    b.add(1, Disc::RED);
    b.add(2, Disc::RED);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.add(6, Disc::YELLOW);
    b.draw();
    cout << endl;
}

// Prints when player makes an invalid move.
void printInvalidMove() {
    cout << "INVALID MOVE! PLEASE ENTER A NUMBER CORRESPONDING TO AN EMPTY COLUMN OR Q to QUIT" << endl << endl;
}

// This function executes the Main Game Loop
void executeGameLoop() {
    Game g = Game();

    while(!g.isOver()) {
        g.display();
        int col;
        cout << "ENTER MOVE: ";

        if(!(cin >> col)) {
            cin.clear();
            char quitCheck;
            if((cin >> quitCheck) && (quitCheck == 'Q'))
                exit(0);
            printInvalidMove();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(!g.makeMove(static_cast<uint8_t>(col)))
            printInvalidMove();
    }

    g.displayEnd();
}

// Main
int main() {
    // Display Intro
    displayIntro();

    // Game Loop
    executeGameLoop();

    return 0;
}