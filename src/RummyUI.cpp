/**
@author: Marianne Quiros
@Date: October 31, 2020
*/
#include "RummyUI.h"
#include <iostream>
#include <string>
#include <list>

unsigned int RummyUI::requestCard(std::list<Card*>* hand) {
    std::cout << "1. Lay down any matched set (meld)" << std::endl;
    std::cout << "2. Pick up Stock Card" << std::endl;
    std::cout << "3. Pick up Discard Card" << std::endl;
    std::cout << "4. Discard a card from your hand" << std::endl;
    std::cout << "What would you like to do?: ";
    unsigned int draw = 0;
    std::cin >> draw;
    return draw;
}

void RummyUI::playFailed() {
  std::cout << "You Lose." << std::endl;
}

void RummyUI::playSucceeded() {
  std::cout << "You Win" << std::endl;
  std::cout << "Counting points..." << std::endl;
}
