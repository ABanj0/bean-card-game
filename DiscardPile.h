#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class DiscardPile {
private:
    std::vector<Card*> cards;

public:
    DiscardPile() = default;
    // Constructor
    DiscardPile(std::istream& in, const CardFactory* cardFactory);

    // Discards the card to the pile
    DiscardPile& operator+=(Card* card);

    // Returns and removes the top card from the discard pile
    Card* pickUp();

    // Returns but does not remove the top card from the discard pile
    Card* top();

    bool isEmpty() const;

    // Inserts all the cards in the DiscardPile to an ostream
    void print(std::ostream& os);

    // Friend function to insert only the top card of the discard pile to an ostream
    friend std::ostream& operator<<(std::ostream& os, const DiscardPile& discardPile);
};

#endif // DISCARDPILE_H