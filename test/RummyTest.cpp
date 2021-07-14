/**
@author: Marianne Quiros
@Date: November 05, 2020
*/
#include "gtest/gtest.h"

#include "MockDeck.h"
#include "MockUI.h"

#include "Card.h"
#include "Game.h"
#include "Rummy.h"


using ::testing::Return;
using ::testing::_;
using ::testing::Expectation;

class RummyTest : public ::testing::Test {
 protected:
  virtual ~RummyTest() {
    delete aceClub;
    delete aceDia;
    delete aceHeart;
    delete aceSpade;

    delete kingClub;
    delete kingDia;
    delete kingHeart;
    delete kingSpade;

    delete twoClub;
    delete twoDia;
    delete twoHeart;
    delete twoSpade;

    delete queenClub;
    delete queenDia;
    delete queenHeart;
    delete queenSpade;

    delete threeClub;
    delete threeDia;
    delete threeHeart;
    delete threeSpade;

    delete jackClub;
    delete jackHeart;
    delete jackSpade;
  }

  Card* aceClub = new Card(Card::CLUB, Card::ACE);
  Card* aceSpade = new Card(Card::SPADE, Card::ACE);
  Card* aceDia = new Card(Card::DIAMOND, Card::ACE);
  Card* aceHeart = new Card(Card::HEART, Card::ACE);

  Card* kingClub = new Card(Card::CLUB, Card::KING);
  Card* kingSpade = new Card(Card::SPADE, Card::KING);
  Card* kingDia = new Card(Card::DIAMOND, Card::KING);
  Card* kingHeart = new Card(Card::HEART, Card::KING);

  Card* twoClub = new Card(Card::CLUB, Card::TWO);
  Card* twoSpade = new Card(Card::SPADE, Card::TWO);
  Card* twoDia = new Card(Card::DIAMOND, Card::TWO);
  Card* twoHeart = new Card(Card::HEART, Card::TWO);

  Card* queenClub = new Card(Card::CLUB, Card::QUEEN);
  Card* queenSpade = new Card(Card::SPADE, Card::QUEEN);
  Card* queenDia = new Card(Card::DIAMOND, Card::QUEEN);
  Card* queenHeart = new Card(Card::HEART, Card::QUEEN);

  Card* threeClub = new Card(Card::CLUB, Card::THREE);
  Card* threeSpade = new Card(Card::SPADE, Card::THREE);
  Card* threeDia = new Card(Card::DIAMOND, Card::THREE);
  Card* threeHeart = new Card(Card::HEART, Card::THREE);

  Card* jackClub = new Card(Card::CLUB, Card::JACK);
  Card* jackSpade = new Card(Card::SPADE, Card::JACK);
  Card* jackHeart = new Card(Card::HEART, Card::JACK);
};

TEST_F(RummyTest, CardDealSmall) {
    MockDeck d;
    MockDeck discard;

    EXPECT_CALL(d, getCard())
    .Times(20)
    .WillRepeatedly(Return(aceClub));

    EXPECT_CALL(d, size())
    .Times(1)
    .WillOnce(Return(20));

    MockUI ui;

    Game* game = new Rummy(&ui, &d, &discard);

    Player* player1 = new Player("John");
    Player* player2 = new Player("Danielle");
    game->addPlayer(player1);
    game->addPlayer(player2);

    game->dealCards(game->getPlayers());

    for (Player* p : game->getPlayers())
        EXPECT_EQ(10, p->getHand()->size());

    delete game;
    delete player1;
    delete player2;
}

TEST_F(RummyTest, CardDealMedium) {
  MockDeck d;
  MockDeck discard;

  EXPECT_CALL(d, getCard())
  .Times(28)
  .WillRepeatedly(Return(aceClub));

  EXPECT_CALL(d, size())
  .Times(1)
  .WillOnce(Return(28));

  MockUI ui;

  Game* game = new Rummy(&ui, &d, &discard);

  Player* player1 = new Player("John");
  Player* player2 = new Player("Danielle");
  Player* player3 = new Player("Tara");
  Player* player4 = new Player("Erik");
  game->addPlayer(player1);
  game->addPlayer(player2);
  game->addPlayer(player3);
  game->addPlayer(player4);

  game->dealCards(game->getPlayers());

  for (Player* p : game->getPlayers())
      EXPECT_EQ(7, p->getHand()->size());

  delete game;
  delete player1;
  delete player2;
  delete player3;
  delete player4;
}

TEST_F(RummyTest, CardDealLarge) {
  MockDeck d;
  MockDeck discard;
  EXPECT_CALL(d, getCard())
  .Times(30)
  .WillRepeatedly(Return(aceHeart));

  EXPECT_CALL(d, size())
  .Times(1)
  .WillOnce(Return(30));

  MockUI ui;

  Game* game = new Rummy(&ui, &d, &discard);

  Player* player1 = new Player("John");
  Player* player2 = new Player("Danielle");
  Player* player3 = new Player("Tara");
  Player* player4 = new Player("Erik");
  Player* player5 = new Player("Bob");
  game->addPlayer(player1);
  game->addPlayer(player2);
  game->addPlayer(player3);
  game->addPlayer(player4);
  game->addPlayer(player5);

  game->dealCards(game->getPlayers());

  for (Player* p : game->getPlayers())
      EXPECT_EQ(6, p->getHand()->size());

  delete game;
  delete player1;
  delete player2;
  delete player3;
  delete player4;
  delete player5;
}

TEST_F(RummyTest, beforeCardPlayed) {
  MockDeck d;
  MockDeck discard;
  MockUI ui;

  EXPECT_CALL(ui, displayUpCard(_))
  .Times(1);

  EXPECT_CALL(ui, displayHand(_))
  .Times(1);

  EXPECT_CALL(ui, requestCard(_))
  .Times(1)
  .WillOnce(Return(2));

  EXPECT_CALL(d, getCard())
  .Times(1)
  .WillOnce(Return(aceHeart));

  Game* game = new Rummy(&ui, &d, &discard);
  Player* player1 = new Player("John");
  Player* player2 = new Player("Danielle");
  game->addPlayer(player1);
  game->addPlayer(player2);
  game->beforeCardPlayed(0, 2);

  EXPECT_EQ(1, player1->getHand()->size());
  EXPECT_EQ(0, player2->getHand()->size());

  delete game;
  delete player1;
  delete player2;
}

TEST_F(RummyTest, start) {
  MockDeck d;
  MockDeck discard;
  MockUI ui;

  EXPECT_CALL(d, shuffle())
  .Times(1);

  EXPECT_CALL(discard, addCard(_))
  .Times(1);

  EXPECT_CALL(ui, showScores(_))
  .Times(1);

  EXPECT_CALL(d, size())
  .Times(1)
  .WillOnce(Return(0));

  EXPECT_CALL(d, getCard())
  .Times(1)
  .WillOnce(Return(aceHeart));

  Game* game = new Rummy(&ui, &d, &discard);
  Player* player1 = new Player("John");
  Player* player2 = new Player("Danielle");
  game->addPlayer(player1);
  game->addPlayer(player2);
  game->start();

  delete game;
  delete player1;
  delete player2;
}
