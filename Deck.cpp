#include "Deck.hpp"

std::wstring stringToUnicode(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

Deck::Deck() {
    for (int i = 0; i <= 12; i++) {
        cardsInDeck.push_back(Card("black", i, Suit::Spade, stringToUnicode("\U0001F0A1"+('0' + i))));
    }

    for (int i = 0; i <= 12; i++) {
        cardsInDeck.push_back(Card("red", i, Suit::Heart, stringToUnicode("\U0001F0B1"+('0' + i))));
    }

    for (int i = 0; i <= 12; i++) {
        cardsInDeck.push_back(Card("red", i, Suit::Diamond, stringToUnicode("\U0001F0C1"+('0' + i))));
    }

    for (int i = 0; i <= 12; i++) {
        cardsInDeck.push_back(Card("black", i, Suit::Club, stringToUnicode("\U0001F0D1"+('0' + i))));
    }
}

Deck::~Deck() {}

void Deck::resetDeck() {
    // Add back all the outside deck cards in deck at random positions
    for (Card card: cardsOutsideDeck) {
        // This is common logic so add it somewhere common
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(0, cardsInDeck.size() - 1);
        int randomPosition = distribution(gen);
        cardsInDeck.insert(cardsInDeck.begin() + randomPosition, card);
    }
    cardsOutsideDeck.clear();
}

void Deck::shuffle() {
    std::random_device rd;
    // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
    std::mt19937 g(rd());
    std::shuffle(cardsInDeck.begin(), cardsInDeck.end(), g);
}

Card Deck::drawCard() {
    Card temp = cardsInDeck.back();
    cardsInDeck.pop_back();
    addToOutsideDeck(temp);
    return temp;
}

void Deck::addToOutsideDeck(Card& card) {
    cardsOutsideDeck.push_back(card);
}
