#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include "Card.h" 
class CardFactory;

class Deck : public std::vector<Card*> {
public:
    Deck() {}
    Deck(std::istream& is, const CardFactory* factory);

    // Removes the top card from the deck
    Card* draw();

    // Insert all the cards in the deck to an ostream
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
};

#endif // DECK_H