#include "Card.hpp"

Card::Card(std::string color, int value, Suit suit, std::wstring uStringRep) : color(color), value(value), suit(suit), unicodeStringRepresentation(uStringRep) {}
Card::~Card() {}

void Card::printCard() {
    
}