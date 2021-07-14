#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
 public:
    virtual ~Deck();
    virtual void shuffle();
    virtual void addCard(Card* card);
    virtual Card* getCard();
    virtual unsigned int size();
    virtual Card* getUpCard();
    void createStandard();
 private:
    std::vector<Card*> deck;
};

#endif // DECK_H
