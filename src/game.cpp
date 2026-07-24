#include "../headers/game.h"

using namespace std;

// Constructor
Game::Game(): board(), currentPlayer(Disc::RED) {}

// Returns the Current Plater
Disc Game::getCurrentPlayer() { return currentPlayer; }

// This function returns a String representing the current state of the game.
void Game::display() {
    board.draw();
    for(int i = 0; i < board.getColumns(); i++)
        cout << i + 1 << " ";
    cout << endl;
    cout << endl << "TURN: " << drawDisc(currentPlayer) << endl;
}

// This function returns a String representing of the final state of the game.
void Game::displayEnd() {
    board.draw();
    for(int i = 0; i < board.getColumns(); i++)
        cout << i + 1 << " ";
    cout << endl << endl;

    if(board.isFull()) {
        cout << ANSI_BLUE << "MATCH TIE 🤝" << endl;
        return;
    }

    if(currentPlayer == Disc::YELLOW) {
        cout << ANSI_RED << "RED WINS 🎉" << endl;
        return;
    }
    cout << ANSI_YELLOW << "YELLOW WINS 🥳" << endl;
}

// Returns boolean indicating if the game is complete.
bool Game::isOver() { return board.isFull() || board.isConnect(); }

// This function executes a move provided by the player by updating the board and changing current player/turn.
bool Game::makeMove(uint8_t column) {
    if(!board.add(column, currentPlayer))
        return false;
        
    currentPlayer = (currentPlayer == Disc::RED) ? Disc::YELLOW : Disc::RED;
    return true;
}