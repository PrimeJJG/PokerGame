#ifndef Deck_h
#define Deck_h

#include "Card.hpp"
#include<vector>
#include <random>
#include <algorithm>

class Deck {
    private:
        std::vector<Card> cardsInDeck; // Represents the full deck
        std::vector<Card> cardsOutsideDeck;
    public:
        Deck(); // init the 52 card deck
        ~Deck();
        void resetDeck();
        void shuffle();
        Card drawCard();
        void addToOutsideDeck(Card& card);
};

#endif // Deck_h