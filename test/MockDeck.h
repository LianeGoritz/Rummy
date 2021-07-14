#ifndef MOCKDECK_H_INCLUDED
#define MOCKDECK_H_INCLUDED

#include "gmock/gmock.h"
#include "Deck.h"
#include "Card.h"

class MockDeck : public Deck {
 public:
    explicit MockDeck() {}
    virtual ~MockDeck() {}

    MOCK_METHOD0(getCard, Card*());
    MOCK_METHOD0(size, unsigned int());
    MOCK_METHOD0(shuffle, void());
    MOCK_METHOD1(addCard, void(Card* card));
    MOCK_METHOD0(getUpCard, Card*());
};

#endif // MOCKDECK_H_INCLUDED
