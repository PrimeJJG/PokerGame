#ifndef Hand_h
#define Hand_h

#include "Deck.hpp"
#include <vector>
#include <algorithm>
#include <unordered_map>

class Hand {
    private:
        // Can keep this to optimize not checking flush and straight again
        // enum class HandEvaluation {
        //     RoyalFlush, ...
        // };
        // HandEvaluation value;
        std::vector<Card> cardsDealt;
        std::unordered_map<int, int> valueCount;
    public:
        Hand(Deck&); // Should have implementation to deal hand?
        ~Hand();
        void addCard(Card&); // to add card to the hand by backend
        void replaceCard(int, Deck&);  // To remove the card from the hand by user
        bool valueCounter(int);
        bool isRoyalFlush();
        bool isFlush();
        bool isStraight();
        bool isStraightFlush();
        bool isFourOfAKind();
        bool isFullHouse();
        bool isThreeOfAKind();
        bool isTwoPairs();
        bool isJacksOrBetter();
        int evaluateHand();
        std::vector<Card>& getCardsDealt();
};

#endif // Hand_h