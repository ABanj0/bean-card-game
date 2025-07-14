#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "Deck.h"
#include "Card.h"
#include <vector>
#include <random>
#include <algorithm>
#include <memory>

class CardFactory {
private:
    CardFactory(); // Private constructor
    static CardFactory* factory; // Only instance of the factory
    std::vector<Card*> cardDeck; // Storage for all cards

public:
    static CardFactory* getFactory();
    Deck getDeck() const;
    static Card* createCard(const std::string& name); // Method to create a card based on a name
};

#endif // CARDFACTORY_H