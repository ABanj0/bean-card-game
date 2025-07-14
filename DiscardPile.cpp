#include "DiscardPile.h"

// Constructor to reconstruct the DiscardPile from an input stream
DiscardPile::DiscardPile(std::istream& in, const CardFactory* cardFactory) {
    std::string cardName;
    while (in >> cardName) {
        Card* card = cardFactory->createCard(cardName);
        if (card) {
            cards.push_back(card);
        }
    }
}

// Discards the card to the pile
DiscardPile& DiscardPile::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Returns and removes the top card from the discard pile
Card* DiscardPile::pickUp() {
    if (cards.empty()) {
        return nullptr;
    }
    Card* topCard = cards.back();
    cards.pop_back();
    return topCard;
}

// Returns but does not remove the top card from the discard pile
Card* DiscardPile::top(){
    if (cards.empty()) {
        return nullptr;
    }
    return cards.back();
}

// Inserts all the cards in the DiscardPile to an ostream
void DiscardPile::print(std::ostream& os){
    for (const Card* card : cards) {
        os << *card << " ";
    }
}

bool DiscardPile::isEmpty() const {
    return cards.empty();
}

// Friend function to insert only the top card of the discard pile to an ostream
std::ostream& operator<<(std::ostream& os, const DiscardPile& discardPile) {
    if (!discardPile.cards.empty()) {
        os << *(discardPile.cards.back());
    }
    return os;
}