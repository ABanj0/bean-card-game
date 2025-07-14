#include "Deck.h"
#include "CardFactory.h"

Deck::Deck(std::istream& is, const CardFactory* factory) {
    std::string cardName;
    while (is >> cardName) {
        Card* card = factory->createCard(cardName);
        if (card) {
            this->push_back(card);
        }
    }
}

Card* Deck::draw() {
    if (this->empty()) {
        return nullptr;
    }
    Card* topCard = this->back();
    this->pop_back();
    return topCard;
}

std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    for (const Card* card : deck) {
        os << card->getName() << " "; 
    }
    return os;
}
