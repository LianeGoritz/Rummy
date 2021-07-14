#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <vector>
#include "Card.h"
#include "Deck.h"
#include "GameUI.h"
#include "Player.h"

class Game {
 public:
    virtual void dealCards(std::vector<Player*> p) = 0;
    virtual void beforeCardPlayed(unsigned int playerNum,
                                  unsigned int numPlayers) = 0;
    virtual void afterCardPlayed(Player* currentPlayer,
                                 std::vector<Player*> players,
                                 Card* played) = 0;
    virtual bool turnOver() = 0;

    /**
    The function starts the game loop for GoFish and Rummy.
    */
    virtual void start() = 0;

    Game(GameUI* ui, Deck* d):deck(d), ui(ui) {}

    /**
    The Game constructor of Rummy or any game that contains another Deck class
    to hold a container of cards.
    @param ui, is a pointer to the GameUI
    @param d, is a pointer to the Deck
    @param discard, is a pointer to the Deck
    */
    Game(GameUI* ui, Deck* d, Deck* discard)
            :deck(d), ui(ui), discard(discard) {}
    virtual ~Game() {}
    virtual bool isOver() const;
    void addPlayer(Player* p);
    std::vector<Player*> getPlayers();
    void addUpCard(Card* card);

 protected:
    std::vector<Player*> players;
    Deck* deck;
    Deck* discard;
    GameUI* ui;
};

#endif // GAME_H_INCLUDED
