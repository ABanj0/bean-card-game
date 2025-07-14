#include "Hand.h"
#include "Card.h"
#include "CardFactory.h"

// Constructor to reconstruct the Hand from an input stream
Hand::Hand(std::istream& in, const CardFactory* cardFactory) {
    std::string cardName;
    while (in >> cardName) {
        Card* card = cardFactory->createCard(cardName);
        if (card) {
            cards.push_back(card);
        }
    }
}

// Adds a card to the rear of the hand
Hand& Hand::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Returns and removes the top card from the player's hand
Card* Hand::play() {
    if (cards.empty()) {
        return nullptr;
    }
    Card* topCard = cards.front();
    cards.erase(cards.begin());
    return topCard;
}

Card* Hand::play(int index) {
    if (index < 0 || index >= static_cast<int>(cards.size())) {
        return nullptr;  // Return nullptr if the index is out of bounds
    }
    auto it = cards.begin();
    std::advance(it, index);  // Move the iterator to the correct position
    Card* selectedCard = *it;  // Get the card at the iterator position
    cards.erase(it);  // Remove the card from the hand
    return selectedCard;
}

// Returns but does not remove the top card from the player's hand
Card* Hand::top(){
    if (cards.empty()) {
        return nullptr;
    }
    return cards.front();
}

// Returns and removes the Card at a given index
Card* Hand::operator[](int index) {
    if (index < 0 || index >= cards.size()) {
        return nullptr;
    }
    auto it = std::next(cards.begin(), index);
    Card* card = *it;
    cards.erase(it);
    return card;
}

size_t Hand::size() const {
    return cards.size();
}

// Friend function to print the Hand on an ostream
std::ostream& operator<<(std::ostream& os, const Hand& hand) {
    for (Card* card : hand.cards) {
        os << card->getName() << " ";
    }
    return os;
}