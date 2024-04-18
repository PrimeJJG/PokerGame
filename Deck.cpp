#include "Deck.hpp"

Deck::Deck() {
    for (int i = 1; i <= 13; i++) {
        Deck.addCard(Card('black', i, suit::Spade, L"\U0001F0A"+std::to_wstring(i))); // Need to change the last one
    }

    for (int i = 1; i <= 13; i++) {
        Deck.addCard(Card('red', i, suit::Heart, L"\U0001F0B"+std::to_wstring(i))); // Need to change the last one
    }

    for (int i = 1; i <= 13; i++) {
        Deck.addCard(Card('red', i, suit::Diamond, L"\U0001F0C"+std::to_wstring(i))); // Need to change the last one
    }

    for (int i = 1; i <= 13; i++) {
        Deck.addCard(Card('black', i, suit::Club, L"\U0001F0D"+std::to_wstring(i))); // Need to change the last one
    }
}