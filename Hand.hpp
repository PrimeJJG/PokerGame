#ifndef Hand
#define Hand

#include "Deck.hpp"
#include <vector>

class Hand {
    private:
        enum class HandEvaluation {
            RoyalFlush, ...
        };
        HandEvaluation value;
        std::vector<Card> cardsDealt;
    public:
        Hand(); // Should have implementation to deal hand?
        void addCard(Card& pickedCard); // to add card to the hand by backend
        void replaceCard(int index);  // To remove the card from the hand by user
        // void printHand();
        // void dealCards(); // Deals 5 cards or add to constructor
        bool isRoyalFlush();
        bool isFlush();
        bool isStraight();
        bool isStraightFlush();
        bool isFourOfAKind();
        bool isFullHouse();
        bool isThreeOfAKind();
        bool isTwoPairs();
        bool isJacksOrBetter();
        void evaluateHand();
};

#endif // Hand