#ifndef PokerGame_h
#define PokerGame_h

#include "Deck.hpp"
#include "Hand.hpp"
#include<vector>
#include<iostream>

class PokerGame {
    private:
        int waged;  // Amount waged by user
        int reward; // Amount recevied as a reward
        int totalWaged;
    public:
        PokerGame(Deck*);
        ~PokerGame();
        int getWaged();
        int getReward();
        void setupGame(Deck&);
        bool startGame();
        bool playAgain();
        void handlePlayerAction(Hand&, Deck&);
        void evaluateRound(Hand&);
        void giveReward(int);
        void getFinalScore();
        void printRules();
        void printScore();
        void printCards(Hand&);
        void wageAmount();
};

#endif // PokerGame_h