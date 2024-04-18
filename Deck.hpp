#ifndef Deck
#define Deck

#include "Card.hpp"
#include<vector>

class Deck {
    private:
        std::vector<Card> deck; // Represents the current deck or full deck?
    public:
        void resetDeck();
        void dealCards();
        void shuffle();
        Card drawCard();
        Deck(); // init the 52 card deck
        ~Deck();
};

#endif // Deck