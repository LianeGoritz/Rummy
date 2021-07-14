#include "GameUI.h"
#include <iostream>
#include <vector>
#include <list>

unsigned int GameUI::choosePlayer(unsigned int playerNum,
                                  unsigned int numPlayers) {
    unsigned int selection = playerNum;
    std::cout << "You are Player #" << playerNum << std::endl;
    while (selection == playerNum || selection >= numPlayers) {
        std::cout << "Which player (0-" << numPlayers-1 << ")? ";
        std::cin >> selection;
        if (selection == playerNum)
            std::cout << "That is you! Please choose another player."
              << std::endl;
        if (selection >= numPlayers)
            std::cout << "Player #" << selection <<
                 " doesn't exist! Please choose another player." << std::endl;
    }
    return selection;
}

void GameUI::showScores(std::vector<Player*> players) {
    std::cout << "---- Scores ----" << std::endl;
    for (Player* player : players)
        std::cout << player->name << ": " << player->getScore() << std::endl;
}

void GameUI::displayHand(std::list<Card*>* hand) {
    std::cout << "Your hand: " << std::endl;
    for (std::list<Card*>::iterator i = hand->begin(); i != hand->end(); ++i) {
      Card::Suit s = (*i)->suit;
      Card::Rank r = (*i)->rank;
      std::cout << Card::getRank(r) << " of " << Card::getSuit(s) << std::endl;
    }
}

void GameUI::displayUpCard(Deck* discard) {
    std::cout << "Discard: " << std::endl;
    std::list<Card*> topDiscard;
    topDiscard.push_back(discard->getUpCard());
    std::list<Card*>::iterator it = topDiscard.begin();
    Card::Suit s = (*it)->suit;
    Card::Rank r = (*it)->rank;
    discard->addCard(*it);
    std::cout << Card::getRank(r) << " of " << Card::getSuit(s) << std::endl;
}
