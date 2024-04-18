#include "PokerGame.hpp"

PokerGame::PokerGame() : waged(0), reward(0) {}

PokerGame::~PokerGame() {}

bool PokerGame::startGame() {
    char start;
    std::cout << "Disclaimer:\nThis game is intended for entertainment purposes only. It is a simulation of a poker game and does not involve real money or gambling.\nBy proceeding to play the game, you acknowledge and agree to the following:\n1. This game does not offer real money gambling or an opportunity to win real money or prizes.\n2. Any rewards or virtual currency earned within the game are purely fictional and have no cash value.\n3. Players should not use this game as a substitute for real-world gambling or betting activities.\n4. The outcome of the game is determined by random chance and skill, and does not guarantee any specific results or winnings.\n5. Users play this game at their own risk, and the creators of the game are not responsible for any loss or harm resulting from its use.\n\nIf you do not agree to these terms, please do not proceed with playing the game. Continue? (y/n)";
    std::cin >> start;
    if (start == 'y') return true;
    else {
        std::cout << "You did not agree to the conditions. Quitting" << std::endl;
        return false;
    }
}

bool PokerGame::playAgain() {
    char choice;
    std::cout << "Play Again? (y/n)" << std::endl;
    std::cin >> choice;
    if (choice == 'y') {
        return true;
    }
}

int PokerGame::getFinalScore() {
    int totWaged = this->getWaged();
    int totReward = this->getReward();
    int diff = totReward - totWaged;
    if (diff < 0) {
        std::cout << "You lost " << -1*diff << " points." << std::endl;
    }
    else {
        std::cout << "You won " << diff << " points." << std::endl;
    }
}

void PokerGame::setupGame() {
    // Will setup a new game by printing rules, dealing cards, etc.
    printRules();
    Hand *hand = new Hand();
    hand->dealCards();
    printCards(); // add this to other
    handlePlayerAction();
    evaluateRound(hand);
}

int PokerGame::getWaged() {
    return this->waged;
}
int PokerGame::getReward() {
    return this->reward;
}

void PokerGame::dealCards() {
    // Might add it to Deck, but this will get 5 cards from the deck
}

void PokerGame::handlePlayerAction() {
    // This will check user input for changing the cards
}

void PokerGame::evaluateRound(Hand& hand) {
    // This will evaluate the cards using rules
    hand->evaluateHand();
}

int PokerGame::giveReward() {
    // This will multiply the waged amount and increase the reward var
}

void PokerGame::printCards() {
    // This will print the game, change code:
    std::cout << "\033[3;1H"; // Move cursor to the row below the rules, change 3 and 1
    std::cout << "\033[0J";   // Clear from cursor position to the end of the screen
}

void PokerGame::printRules() {
    std::string rules = "Pattern\tMultiplier\n"
    "Royal Flush\tx250\n";
    "Straight Flush\tx50\n";
    "Four of a kind\tx25\n";
    "Full House\tx9\n";
    "Flush\tx6\n";
    "Straight\tx4\n";
    "Three of a kind\tx3\n";
    "Two Pairs\tx2\n";
    "Jacks or better\tx1\n";
    std::cout << rules;
}

void PokerGame::printScore() {
    // This will print waged amount and reward at the end of screen
}