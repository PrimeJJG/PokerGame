#ifndef Card_h
#define Card_h

#include <string>
#include <iostream>

enum class Suit {
    Club, Diamond, Heart, Spade
};

class Card {
    private:
        std::string color;  // red, black
        int value;  // Number
        Suit suit;
        std::wstring unicodeStringRepresentation;
    public:
        Card(std::string color, int value, Suit suit, std::wstring unicodeStringRepresentation);
        ~Card();
        void printCard();
        int getValue();
        Suit getSuit();
        std::string suitToString(Suit suit);
        bool operator<(const Card) const;
};

#endif // Card_h