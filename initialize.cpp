#include "PokerGame.hpp"

int main() {
    char startGame;
    Deck* deck = new Deck();
    PokerGame* newGame = new PokerGame(deck);
    if (newGame->startGame()) {
        bool quit = false;
        while (!quit) {
            newGame->setupGame(*deck);
            if (newGame->playAgain()) {
                continue;
            }
            else {
                quit = true;
                newGame->getFinalScore();
                delete newGame;
                delete deck;
            }
        }
        return 0;
    } 
    else {
        return 0;
    }
}