#include "Hand.hpp"

Hand::Hand(Deck& deck) {
    for (int i = 1; i <= 5; i++) {
        Card picked = deck.drawCard();
        addCard(picked);
        // picked.printCard(); // Might have to give dynamic position
    }
    for (Card& card : cardsDealt) {
        valueCount[card.getValue()]++;
    }
}

Hand::~Hand() {}

void Hand::addCard(Card& pickedCard) {
    cardsDealt.push_back(pickedCard);
}

void Hand::replaceCard(int index, Deck& deck) {
    Card temp = cardsDealt[index - 1];
    valueCount[temp.getValue()]--;
    cardsDealt[index - 1] = deck.drawCard();
    valueCount[cardsDealt[index - 1].getValue()]++;
}

bool Hand::valueCounter(int count) {
    for (const auto& pair : this->valueCount) {
        if (pair.second == count) {
            return true;
        }
    }
    return false;
}

bool Hand::isRoyalFlush() {
    sort(cardsDealt.begin(), cardsDealt.end());
    if (cardsDealt[0].getValue() != 1) return false;
    if (cardsDealt[1].getValue() != 10) return false;
    return isFlush();
}

bool Hand::isFlush() {
    Suit starter = cardsDealt[0].getSuit();
    for (int i = 1; i < 5; i++) {
        if (cardsDealt[i].getSuit() != starter) {
            return false;
        }
    }
    return true;
}

bool Hand::isStraight() {
    if (cardsDealt[0].getValue() == 1 && cardsDealt[1].getValue() == 10) return true;
    int starter = cardsDealt[0].getValue();
    starter++;
    for (int i = 1; i < 5; i++) {
        if (cardsDealt[i].getValue() != starter) {
            return false;
        }
        starter++;
    }
    return true;
}

bool Hand::isStraightFlush() {
    return isStraight() && isFlush();
}

bool Hand::isFourOfAKind() {
    return valueCounter(4);
}

bool Hand::isFullHouse() {
    return valueCounter(3) && valueCounter(2);
}

bool Hand::isThreeOfAKind() {
    return valueCounter(3);
}

bool Hand::isTwoPairs() {
    int count = 0;
    for (const auto& pair : valueCount) {
        if (pair.second == 2) {
            count++;
        }
    }
    return (count == 2); 
}

bool Hand::isPair() {
    return valueCounter(2);
}

bool Hand::isJacksOrBetter() {
    return (valueCount[1] >= 2 || valueCount[11] >= 2 || valueCount[12] >= 2 || valueCount[13] >= 2);
}

HandRank Hand::evaluateHand() {
    if (isRoyalFlush()) return HandRank::RoyalFlush;
    if (isFlush()) return HandRank::Flush;
    if (isStraight()) return HandRank::Straight;
    if (isStraightFlush()) return HandRank::StraightFlush;
    if (isFourOfAKind()) return HandRank::FourOfAKind;
    if (isFullHouse()) return HandRank::FullHouse;
    if (isThreeOfAKind()) return HandRank::ThreeOfAKind;
    if (isTwoPairs()) return HandRank::TwoPairs;
    if (isPair()) return HandRank::Pair;
    if (isJacksOrBetter()) return HandRank::JacksOrBetter;
    return HandRank::None;
}

std::vector<Card>& Hand::getCardsDealt() {
    return cardsDealt;
}

int Hand::getScoreForRank(HandRank rank) {
    switch (rank) {
        case HandRank::RoyalFlush:     return 250;
        case HandRank::Flush:          return 50;
        case HandRank::Straight:       return 25;
        case HandRank::StraightFlush:  return 9;
        case HandRank::FourOfAKind:    return 6;
        case HandRank::FullHouse:      return 4;
        case HandRank::ThreeOfAKind:   return 3;
        case HandRank::TwoPairs:       return 2;
        case HandRank::Pair:           return 1;
        case HandRank::JacksOrBetter:  return 0.5;
        default:                       return 0;
    }
}

std::string Hand::getMessageForRank(HandRank rank) {
    switch (rank) {
        case HandRank::RoyalFlush:     return "You got a Royal Flush!\n";
        case HandRank::Flush:          return "You got a Flush!\n";
        case HandRank::Straight:       return "You got a Straight!\n";
        case HandRank::StraightFlush:  return "You got a Straight Flush!\n";
        case HandRank::FourOfAKind:    return "You got Four of a Kind!\n";
        case HandRank::FullHouse:      return "You got a Full House!\n";
        case HandRank::ThreeOfAKind:   return "You got Three of a Kind!\n";
        case HandRank::TwoPairs:       return "You got Two Pairs!\n";
        case HandRank::Pair:           return "You got a Pair!\n";
        case HandRank::JacksOrBetter:  return "You got Jacks or Better!\n";
        default:                       return "";
    }
}
