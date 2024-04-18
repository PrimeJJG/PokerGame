#include "PokerGame.hpp"

int main() {
    char startGame;
    PokerGame *newGame = new PokerGame();
    if (newGame->startGame()) {
        bool quit = false;
        while (!quit) {
            newGame->setupGame();
            if (newGame->playAgain()) {
                continue;
            }
            else {
                quit = true;
                newGame->getFinalScore();
                delete newGame;
            }
        }
        return 0;
    } 
    else {
        return 0;
    }
}