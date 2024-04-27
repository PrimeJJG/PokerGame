#include "Card.hpp"

Card::Card(std::string color, int value, Suit suit, std::wstring uStringRep) : color(color), value(value), suit(suit), unicodeStringRepresentation(uStringRep) {}
Card::~Card() {}

void Card::printCard() {
    // std::wcout<<unicodeStringRepresentation<<std::endl;
    std::cout << color << " " << value << std::endl;
}

int Card::getValue() {
    return value;
}

Suit Card::getSuit() {
    return suit;
}

bool Card::operator<(const Card other) const {
    if (value != other.value) {
        return value < other.value;
    }
    return suit < other.suit;
}