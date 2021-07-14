#include "Card.h"
#include <string>

std::string Card::getRank(const Card::Rank rank) {
    switch (rank) {
    case Card::ACE :
        return "Ace";
    case Card::TWO :
        return "2";
    case Card::THREE :
        return "3";
    case Card::FOUR :
        return "4";
    case Card::FIVE :
        return "5";
    case Card::SIX :
        return "6";
    case Card::SEVEN :
        return "7";
    case Card::EIGHT :
        return "8";
    case Card::NINE :
        return "9";
    case Card::TEN :
        return "Ten"; //Added the full rank name instead of the just the letter
    case Card::JACK :
        return "Jack";
    case Card::QUEEN :
        return "Queen";
    case Card::KING :
        return "King";
    }
    return "?";
}

std::string Card::getSuit(const Card::Suit suit) {
    switch (suit) {
    case Card::CLUB:
        return "Club"; //Added the full suit name instead of just the letter
    case Card::DIAMOND:
        return "Diamond";
    case Card::SPADE:
        return "Spade";
    case Card::HEART:
        return "Heart";
    }
    return "?";
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << Card::getRank(c.rank) << ":" << Card::getSuit(c.suit);
    return os;
}
