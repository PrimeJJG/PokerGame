#ifndef PokerGame
#define PokerGame

#include "Card.hpp"
#include "Deck.hpp"
#include<vector>
#include<iostream>

class PokerGame {
    private:
        int waged;  // Amount waged by user
        int reward; // Amount recevied as a reward
    public:
        PokerGame();
        ~PokerGame();
        int getWaged();
        int getReward();
        void setupGame();
        bool startGame();
        bool playAgain();
        void dealCards();
        void handlePlayerAction();
        void evaluateRound();
        int giveReward();
        int getFinalScore();
        void printGame();
        void printRules();
        void printScore();
};

#endif // PokerGame