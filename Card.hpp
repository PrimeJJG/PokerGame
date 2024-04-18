// There will be a function which checks if a pattern is present
// There will be a function for each pattern
// All cards will be stored in one single data structure so that probability is maintained
// User will be shown all patterns on top, 
// then asked to wager an amount/points
// then cards will be revealed.
// They can then select using number which ones to switch. Once entered, all these will be
// simultaneously switched. If none is switched, all will be kept
// There will be a display of waged and earned.
// Once the user finishes the game, the final points will be calculated.
// There will also be a warning message saying not to bet.
// Deck, cards on table, cards removed from deck and table

#ifndef Card
#define Card

#include <string>

class Card {
    private:
        std::string color;  // red, black
        int value;  // Number
        enum class Suit {
            Club, Diamond, Heart, Spade
        };
        Suit suit;
        std::wstring unicodeStringRepresentation;
    public:
        Card(std::string color, int value, Suit suit, std::wstring unicodeStringRepresentation);
        ~Card();
        void printCard();
};

#endif // Card