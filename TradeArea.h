#ifndef TRADEAREA_H
#define TRADEAREA_H

#include <list>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class TradeArea {
private:
    std::list<Card*> cards;

public:
    TradeArea() = default;
    // Constructor to reconstruct the TradeArea from an input stream
    TradeArea(std::istream& in, const CardFactory* cardFactory);

    // Adds the card to the trade area
    TradeArea& operator+=(Card* card);

    // Returns true if the card can be legally added to the TradeArea
    bool legal(Card* card);

    // Removes a card of the corresponding bean name from the trade area
    Card* trade(std::string beanName);

    // Returns the number of cards currently in the trade area
    int numCards();

    bool isEmpty() const;

    Card* top() const;
    // Friend function to insert all the cards of the trade area to an ostream
    friend std::ostream& operator<<(std::ostream& os,const TradeArea& tradeArea);
};

#endif // TRADEAREA_H