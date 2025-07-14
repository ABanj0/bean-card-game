#include "TradeArea.h"

// Constructor to reconstruct the TradeArea from an input stream
TradeArea::TradeArea(std::istream& in, const CardFactory* cardFactory) {
    std::string cardName;
    while (in >> cardName) {
        Card* card = cardFactory->createCard(cardName);
        if (card) {
            cards.push_back(card);
        }
    }
}

// Adds the card to the trade area
TradeArea& TradeArea::operator+=(Card* card) {
    cards.push_back(card);
    return *this;
}

// Returns true if the card can be legally added to the TradeArea
bool TradeArea::legal(Card* card){
    for (Card* c : cards) {
        if (c->getName() == card->getName()) {
            return true;
        }
    }
    return false;
}

bool TradeArea::isEmpty() const {
    return cards.empty();
}
// Removes a card of the corresponding bean name from the trade area
Card* TradeArea::trade(std::string beanName) {
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        if ((*it)->getName() == beanName) {
            Card* card = *it;
            cards.erase(it);
            return card;
        }
    }
    return nullptr;
}

// Returns the number of cards currently in the trade area
int TradeArea::numCards(){
    return cards.size();
}

Card* TradeArea::top() const {
    if (!cards.empty()) {
        return cards.back();
    }
    return nullptr;
}

// Friend function to insert all the cards of the trade area to an ostream
std::ostream& operator<<(std::ostream& os,const TradeArea& tradeArea) {
    for (Card* card : tradeArea.cards) {
        os << card->getName() << " ";
    }
    return os;
}