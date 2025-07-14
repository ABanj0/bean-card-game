#ifndef HAND_H
#define HAND_H

#include <list>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class Hand {
private:
    std::list<Card*> cards;
public:
    Hand() = default;
    // Constructor to reconstruct the Hand from an input stream
    Hand(std::istream& in, const CardFactory* cardFactory);

    size_t size() const;

    // Adds a card to the rear of the hand
    Hand& operator+=(Card* card);

    // Returns and removes the top card from the player's hand
    Card* play();

    Card* play(int index);
    // Returns but does not remove the top card from the player's hand
    Card* top();

    // Returns and removes the Card at a given index
    Card* operator[](int);

    // Friend function to print the Hand on an ostream
    friend std::ostream& operator<<(std::ostream& os, const Hand& hand);
};

#endif // HAND_H