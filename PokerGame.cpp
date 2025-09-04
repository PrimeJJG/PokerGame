#include "PokerGame.hpp"

PokerGame::PokerGame(Deck* deck) : waged(0), reward(0), totalWaged(0) {}

PokerGame::~PokerGame() {}

bool PokerGame::startGame() {
    char start;
    std::cout << "Disclaimer:\nThis game is intended for entertainment purposes only. It is a simulation of a poker game and does not involve real money or gambling.\nBy proceeding to play the game, you acknowledge and agree to the following:\n1. This game does not offer real money gambling or an opportunity to win real money or prizes.\n2. Any rewards or virtual currency earned within the game are purely fictional and have no cash value.\n3. Players should not use this game as a substitute for real-world gambling or betting activities.\n4. The outcome of the game is determined by random chance and skill, and does not guarantee any specific results or winnings.\n5. Users play this game at their own risk, and the creators of the game are not responsible for any loss or harm resulting from its use.\n\nIf you do not agree to these terms, please do not proceed with playing the game. Continue? (y/n) ";
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
    return (choice == 'y');
}

void PokerGame::getFinalScore() {
    // int totWaged = this->getTotalWaged();
    // int totReward = this->getReward();
    int diff = reward - totalWaged;
    if (diff < 0) {
        std::cout << "You lost " << -1*diff << " points." << std::endl;
    }
    else {
        std::cout << "You won " << diff << " points. (Profit)" << std::endl;
    }
    // Add logic to clear console
}

void PokerGame::setupGame(Deck& deck) {
    // Will setup a new game by printing rules, dealing cards, etc.
    printRules();
    for (int i = 0; i < 5; i++) {
        deck.shuffle();
    }
    Hand *hand = new Hand(deck);
    printCards(*hand);
    wageAmount();
    handlePlayerAction(*hand, deck);
    printCards(*hand);
    evaluateRound(*hand);
    printScore();
    deck.resetDeck();
}

void PokerGame::wageAmount() {
    std::cout << "Enter Amount to Wage: ";
    int amount;
    std::cin >> amount;
    totalWaged += amount;
    waged = amount;
}

int PokerGame::getWaged() {
    return this->waged;
}
int PokerGame::getReward() {
    return this->reward;
}

void PokerGame::handlePlayerAction(Hand& hand, Deck& deck) {
    // This will check user input for changing the cards
    std::string input;
    std::cout << std::endl;
    std::cout << "Enter Positions to Replace Cards. E.g. If you want to select positions 1, 2 and 4, type 124.\nTo not replace any card and continue with current hand, press 0.\nHit enter." << std::endl;
    std::cin >> input;
    for (auto c: input) {
        if (c-'0' > 5 || c-'0' < 0) {
            std::cout << "Invalid Input, Try Again\n";
            handlePlayerAction(hand, deck);
        }
        else {
            if (c - '0' == 0) return;
            hand.replaceCard(c - '0', deck);
        }
    }
}

void PokerGame::evaluateRound(Hand& hand) {
    // This will evaluate the cards using rules
    HandRank rank = hand.evaluateHand();
    int score = hand.getScoreForRank(rank);
    std::string message = hand.getMessageForRank(rank);
    std::cout << message << "You won " << score << " times your waged amount!" << std::endl;
    giveReward(score);
}

void PokerGame::giveReward(int multiplier) {
    // This will multiply the waged amount and increase the reward var
    reward += (waged * multiplier);
}

void PokerGame::printCards(Hand& hand) {
    // This will print the game, change code:
    // std::cout << "\033[3;1H"; // Move cursor to the row below the rules, change 3 and 1
    // std::cout << "\033[0J";   // Clear from cursor position to the end of the screen
    auto currentCards = hand.getCardsDealt();
    for (auto card: currentCards) {
        card.printCard();
    }
}

void PokerGame::printRules() {
    std::string rules = "Pattern\t\tMultiplier\n"
    "Royal Flush\tx250\n"
    "Straight Flush\tx50\n"
    "Four of a kind\tx25\n"
    "Full House\tx9\n"
    "Flush\t\tx6\n"
    "Straight\tx4\n"
    "Three of a kind\tx3\n"
    "Two Pairs\tx2\n"
    "Pair\tx1\n"
    "Jacks or better\tx1\n";
    std::cout << rules;
}

void PokerGame::printScore() {
    std::cout << "Current Waged: " << waged << " Total Waged: " << totalWaged << " Total Reward: " << reward << std::endl;
}