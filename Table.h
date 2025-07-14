#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"

class Table {
public:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;

    // Constructor to reconstruct the Table from an input stream
    Table(std::istream& in, const CardFactory* cardFactory);

    void setDeck(const Deck& newDeck) {
        this->deck = newDeck;
    }
    // Returns true when a player has won
    bool win(std::string& playerName);

    // Prints the top card of the player's hand or all of the player's hand
    void printHand(bool all);

    // Friend function to print a Table to an ostream
    friend std::ostream& operator<<(std::ostream& os, const Table& table);
};

#endif // TABLE_H