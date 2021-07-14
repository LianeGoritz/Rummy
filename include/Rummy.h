/**
@author: Marianne Quiros
@Date: October 31, 2020
*/
#ifndef RUMMY_H
#define RUMMY_H

#include "Game.h"
#include <vector>
#include <list>

class Rummy : public Game {
 public:
    /**
    The constructor for the Rummy class that inherits from the game class.
    @param ui, is a pointer to GameUI
    @param d, is a Deck that contains a vector of Cards
    @param discard, is a Deck that contains a vecotr of discarded cards.
    */
    Rummy(GameUI* ui, Deck* d, Deck* discard) : Game(ui, d, discard) {}

    /**
    The destructor function
    */
    virtual ~Rummy() {}

    /**
    The function that deals the cards to the players.
    @param p is considered as a vector type called Player.
    @return void
    */
    virtual void dealCards(std::vector<Player*> p);

    /**
    The function that sets up the game before playing.
    @
    */
    virtual void beforeCardPlayed(unsigned int playerNum,
                          unsigned int numPlayers);

    /**
    The function that sets up the game after the cards has been dealt.
    */
    void afterCardPlayed(Player* currentPlayer,
              std::vector<Player*> players, Card* played);

    /**
    The game loop function
    */
    virtual void start();

    /**
    The function that determines whether or not the player's turn is over.
    @return true if the player is done his/her turn, else return false.
    */
    bool turnOver();

    /**
    The function that determines whether or not the player has four of a kind.
    @param hand, is a pointer to a list of type Card
    @return true, if the player has 4 of a kind else, player doesnt have four
    of a kind.
    */
    virtual bool sets(std::list<Card*>* hand);

    /**
    The function that tallies the points of the player.
    */
    virtual void addingPoints(std::vector<Player*> player) {
    }

 protected:
    unsigned int playerAsked = -1;

 private:
    /**
    The attributes that determines the number of players.
    The attributes are considered constant because we do not want the user to
    manipulate the number of players that the game can legally have.
    */
    const unsigned int NUM_PLAYERS_SMALL = 10; //2 players
    const unsigned int NUM_PLAYERS_MEDIUM = 7; //3 to 4 players
    const unsigned int NUM_PLAYERS_LARGE = 6; //5-6 players
};
#endif //RUMMY_H_
