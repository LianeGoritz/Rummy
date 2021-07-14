/**
@author: Marianne Quiros
@Date: October 31, 2020
*/
#include "Rummy.h"
#include "Exceptions.h"
#include <vector>
#include <list>

void Rummy::dealCards(std::vector<Player*> p) {
    //Determines how many players in the game
    unsigned int nCards;
    if (p.size() == 2)
      nCards = NUM_PLAYERS_SMALL;
    else if (p.size() == 3 || p.size() == 4)
      nCards = NUM_PLAYERS_MEDIUM;
    else
      nCards = NUM_PLAYERS_LARGE;

    //Dealing the number of cards by the number of players involved
    //in the game
    unsigned int deckSize = deck->size();
    unsigned int neededCards = p.size() * nCards;

    if (deckSize >= neededCards) {
      unsigned int pNum = 0;
      for (unsigned int i = 0; i < neededCards; i++) {
        Player* player = p.at(pNum);
        player->addCard(deck->getCard());
        pNum = (++pNum) % p.size();
      }
    }
}

void Rummy::beforeCardPlayed(unsigned int playerNum,
                              unsigned int numPlayers) {
    //Display the up card of the discard pile.
    ui->displayUpCard(discard);

    //Display the card that the player has in their Hand
    Player* player = players.front();
    player = players.at(playerNum);
    player->sortHand();
    std::cout << std::endl;
    ui->displayHand(player->getHand());

    //Ask for the player's decision
    std::cout << std:: endl;
    unsigned int option;
    option = ui->requestCard(player->getHand());
    if (option == 1) {
      std::cout << "You chose to 'Lay down any matched set (meld)'"
                << std::endl << std::endl;
    } else if (option == 2) {
      std::cout << "Adding stock card to your hand." << std::endl;
      player->addCard(deck->getCard());
      std::cout << std::endl;
    } else if (option == 3) {
      std::cout << "Adding discarded card to your hand." << std::endl;
      player->addCard(discard->getUpCard());
      std::cout << std::endl;
    } else {
      std::cout << "You chose to 'Discard a card from your hand'"
                << std::endl;
      discard->addCard(player->getCard(0));
      std::cout << std::endl;
    }
}

void Rummy::afterCardPlayed(Player* currentPlayer,
    std::vector<Player*> players, Card* played) {
    //melds
}

void Rummy::start() {
    if (players.empty())
      throw game_init_error("No players for game.");

    //Dealing cards
    deck->shuffle();
    dealCards(players);
    discard->addCard(deck->getCard());

    //Game loop here
    unsigned int turn = 0;
    Card* card;
    Player* player = players.front();
    while (!isOver()) {
      player = players.at(turn);
      do {
        beforeCardPlayed(turn, players.size());
        sets(player->getHand());
        //afterCardPlayed(player, players, card);
      } while (!turnOver());
      addingPoints(getPlayers());
      turn = ++turn % players.size();
    }
    ui->showScores(players);
}

bool Rummy::turnOver() {
  return true;
}

bool Rummy::sets(std::list<Card*>* hand) {
    std::list<Card*> toRemove;
    for (std::list<Card*>::iterator checking = hand->begin();
          checking != hand->end(); ++checking) {
      toRemove.clear();
      unsigned int count = 0;
      for (std::list<Card*>::iterator card = hand->begin();
          card != hand->end(); ++card) {
          if ((*checking)->rank == (*card)->rank) {
            count++;
            toRemove.push_back(*card);
          }
        }
    if (count == 3 || count == 4) {
      for (std::list<Card*>::iterator card = toRemove.begin();
                  card != toRemove.end(); ++card)
            hand->remove(*card);
        return true;
      }
    }
    return false;
}

void addingPoints(std::vector<Player*> player) {
  unsigned int num = 0;
  if (player[num]->getHand()->empty()) {
    for (int i = 0; i < player.size(); i++) {
      std::list<Card*>* hand = player.at(i)->getHand();
      for (std::list<Card*>::iterator it = hand->begin();
                it != hand->end(); it++) {
        Card::Rank r = (*it)->rank;
        if (Card::getRank(r) == "Ace")
          player[num]->addPoints(1);
        if (Card::getRank(r) == "Jack" || Card::getRank(r) == "Queen" ||
              Card::getRank(r) == "King")
          player[num]->addPoints(10);
        else
          player[num]->addPoints(std::stoi(Card::getRank(r)));
      }
    }
    num++;
  }
}
