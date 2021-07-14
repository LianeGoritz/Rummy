#ifndef GAMEUI_H_INCLUDED
#define GAMEUI_H_INCLUDED

#include <list>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class GameUI {
 public:
    GameUI() {}
    virtual ~GameUI() {}

    virtual unsigned int requestCard(std::list<Card*>* hand) = 0;
    virtual void playFailed() = 0;
    virtual void playSucceeded() = 0;
    virtual unsigned int choosePlayer(unsigned int playerNum,
                                      unsigned int numPlayers);
    virtual void showScores(std::vector<Player*> players);

    /**
    The function that displays the cards that are in the player's hand.
    @param hand is a list of Cards in the player's current hand.
    @return void
    */
    virtual void displayHand(std::list<Card*>* hand);

    /**
    The function that displays the up Card of the discard pile.
    @param discard, is a pointer to type Deck
    */
    virtual void displayUpCard(Deck* discard);
};

#endif // GAMEUI_H_INCLUDED
