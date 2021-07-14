/**
@author: Marianne Quiros
@Date: October 31, 2020
*/
#ifndef RUMMYUI_H
#define RUMMYUI_H

#include "GameUI.h"
#include "Card.h"
#include <list>

class RummyUI : public GameUI {
 public:
    /**
    Constructor function
    */
    RummyUI() {}

    /**
    Destructor function
    */
    virtual ~RummyUI() {}

    /**
    The function that displays the player's choices.
    @param hand, is a pointer to a pointer of list of cards.
    @return unsigned int, the decision of the player is returned
    */
    unsigned int requestCard(std::list<Card*>* hand);

    /**
    The function that displays a message that the player has lost the game.
    */
    void playFailed();

    /**
    The function that displays a message that the player has won the game.
    */
    void playSucceeded();

    /**
    This function displays the options that the player has during
    their turn.
    */
    //unsigned int playerChoices();

    /**
    The function that displays the message of which pile the player would
    like to draw from.
    @return void
    */
    //void pickUp_UpCard();

    /**
    The function that displays the message that the player has no Cards
    left in their hand and has won the game.
    */
    //void emptyHand();
};
#endif //RUMMYUI_H
