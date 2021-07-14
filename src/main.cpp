#include "Deck.h"
#include "GoFishUI.h"
#include "GoFish.h"
#include "Rummy.h"
#include "RummyUI.h"
#include <string>

int main() {
    std::cout << "1. GoFish" << std::endl;
    std::cout << "2. Rummy" << std::endl;
    std::cout << "Select a game to play: ";
    std::string pickGame;
    while (std::cin >> pickGame) {
      if (pickGame == "1" || pickGame == "GoFish") {
        std::cout << std::endl;
        std::cout << "You are now playing 'GoFish'." << std::endl;
        std::cout << std::endl;
        Deck* d = new Deck();
        d->createStandard();
        GameUI* ui = new GoFishUI();
        Game* g = new GoFish(ui, d);
        Player* player1 = new Player("John");
        Player* player2 = new Player("Danielle");
        Player* player3 = new Player("Tara");
        Player* player4 = new Player("Erik");
        Player* player5 = new Player("Kira");
        g->addPlayer(player1);
        g->addPlayer(player2);
        g->addPlayer(player3);
        g->addPlayer(player4);
        g->addPlayer(player5);

        g->start();

        delete d;
        delete ui;
        delete g;
        delete player1;
        delete player2;
        delete player3;
        delete player4;
        delete player5;
        break;
      } else if (pickGame == "2" || pickGame == "Rummy") {
        std::cout << std::endl;
        std::cout << "You are now playing the game 'Rummy'." << std::endl;
        std::cout << std::endl;
        //Starting game
        Deck* d = new Deck();
        Deck* discard = new Deck();
        d->createStandard();
        GameUI* ui = new RummyUI();
        Game* g = new Rummy(ui, d, discard);

        //Adding Players
        Player* player1 = new Player("John");
        Player* player2 = new Player("Danielle");
        Player* player3 = new Player("Tara");
        Player* player4 = new Player("Erik");
        Player* player5 = new Player("Kira");
        g->addPlayer(player1);
        g->addPlayer(player2);
        g->addPlayer(player3);
        g->addPlayer(player4);
        g->addPlayer(player5);

        g->start();

        //Deleting appropraite memory
        delete d;
        delete ui;
        delete g;
        delete player1;
        delete player2;
        delete player3;
        delete player4;
        delete player5;
        break;
    } else {
      std::cout << std::endl;
      std::cout << "Invalid input. Please try again." << std::endl;
      std::cout << std::endl << "1. GoFish" << std::endl;
      std::cout << "2. Rummy" << std::endl;
      std::cout << "Select a game to play: ";
    }
  }
}
