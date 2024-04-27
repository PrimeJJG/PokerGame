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

bool Hand::isJacksOrBetter() {
    return (valueCount[1] >= 2 || valueCount[11] >= 2 || valueCount[12] >= 2 || valueCount[13] >= 2);
}

int Hand::evaluateHand() {
    if (isRoyalFlush()) {
        std::cout << "You got a Royal Flush!" << std::endl;
        return 250;
    }
    if (isFlush()) {
        std::cout << "You got a Flush!" << std::endl;
        return 50;
    }
    if (isStraight()) {
        std::cout << "You got a Straight!" << std::endl;
        return 25;
    }
    if (isStraightFlush()) {
        std::cout << "You got a Straight Flush!" << std::endl;
        return 9;
    }
    if (isFourOfAKind()) {
        std::cout << "You got Four of a Kind!" << std::endl;
        return 6;
    }
    if (isFullHouse()) {
        std::cout << "You got a Full House!" << std::endl;
        return 4;
    }
    if (isThreeOfAKind()) {
        std::cout << "You got Three of a Kind!" << std::endl;
        return 3;
    }
    if (isTwoPairs()) {
        std::cout << "You got Two Pairs!" << std::endl;
        return 2;
    }
    if (isJacksOrBetter()) {
        std::cout << "You got Jacks or better!" << std::endl;
        return 1;
    }
    else return 0;
}

std::vector<Card>& Hand::getCardsDealt() {
    return cardsDealt;
}