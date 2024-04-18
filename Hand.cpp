#include "Hand.hpp"

Hand::Hand() {
    // Should it be called here?
    Deck deck* = new Deck();
    for (int i = 1; i <= 5; i++) {
        Card picked = deck->drawCard();
        addCard(picked);
    }
}

Hand::~Hand() {}

void Hand::addCard(Card& pickedCard) {
    cardsDealt.push_back(pickedCard);
}

void Hand::replaceCard(int index) {
    // Should not use deck here directly?
    cardsDealt[index] = deck->drawCard();
}

bool Hand::isRoyalFlush() {

}

void Hand::evaluateHand() {
    
}