#include "Card.hpp"

Card::Card(std::string color, int value, Suit suit, std::wstring uStringRep) : color(color), value(value), suit(suit), unicodeStringRepresentation(uStringRep) {}
Card::~Card() {}

void Card::printCard() {
    if (value == 0 || value >= 10) {
        // For face cards and Ace
        std::string face = "";
        switch(value) {
            case 0:
                face = "A";
                break;
            case 10:
                face = "J";
                break;
            case 11:        
                face = "Q";
                break;
            case 12:
                face = "K";
                break;
            default:
                face = "?";
        }
        std::cout << suitToString(suit) << " " << face << std::endl;
    }
    else {
        // For numbered cards
        std::cout << suitToString(suit) << " " << value + 1 << std::endl;
    }
}

int Card::getValue() {
    return value;
}

Suit Card::getSuit() {
    return suit;
}

std::string Card::suitToString(Suit suit) {
    switch(suit) {
        case Suit::Club:
            return "Club";
        case Suit::Diamond:
            return "Diamond";
        case Suit::Heart:
            return "Heart";
        case Suit::Spade:
            return "Spade";
        default:
            return "Unknown Suit";
    }
}

bool Card::operator<(const Card other) const {
    if (value != other.value) {
        return value < other.value;
    }
    return suit < other.suit;
}