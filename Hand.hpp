#ifndef Hand_h
#define Hand_h

#include "Deck.hpp"
#include <vector>
#include <algorithm>
#include <unordered_map>

enum class HandRank {
    None,
    JacksOrBetter,
    Pair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};

class Hand {
    private:
        std::vector<Card> cardsDealt;
        std::unordered_map<int, int> valueCount;
        HandRank rank;
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
        bool isPair();
        bool isJacksOrBetter();
        HandRank evaluateHand();
        std::vector<Card>& getCardsDealt();
        int getScoreForRank(HandRank);
        std::string getMessageForRank(HandRank);
};

#endif // Hand_h