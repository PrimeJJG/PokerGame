#include<iostream>
#include<random>

void moveCursor(int x, int y) {
    std::cout << "\033[" << x << ";" << y << "H";
}

int randomGenerator() {
    std::random_device rd;
    std::mt19937 gen(rd());
}