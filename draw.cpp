#include<iostream>

void moveCursor(int x, int y) {
    std::cout << "\033[" << x << ";" << y << "H";
}