#include "Table.h"

Table::Table(std::istream& in, const CardFactory* cardFactory) {
    std::string player1Name, player2Name;

    in >> player1Name >> player2Name;

    player1 = Player(player1Name);
    player2 = Player(player2Name);

    deck = Deck(in, cardFactory);
    discardPile = DiscardPile(in, cardFactory);
    tradeArea = TradeArea(in, cardFactory);
}

// Returns true when a player has won
bool Table::win(std::string& playerName) {
    if (deck.empty()) {
        if (player1.getNumCoins() > player2.getNumCoins()) {
            playerName = player1.getName();
            return true;
        } else if (player2.getNumCoins() > player1.getNumCoins()) {
            playerName = player2.getName();
            return true;
        } else {
            playerName = "Draw";
            return true;
        }
    }
    return false;
}

// Prints the top card of the player's hand or all of the player's hand
void Table::printHand(bool all) {
    std::cout << "Player 1's hand: ";
    player1.printHand(std::cout, all);
    std::cout << "\nPlayer 2's hand: ";
    player2.printHand(std::cout, all);
    std::cout << std::endl;
}

// Friend function to print a Table to an ostream
std::ostream& operator<<(std::ostream& os, const Table& table) {
    os << "Player 1: " << table.player1 << "\n";
    os << "Player 2: " << table.player2 << "\n";
    os << "Deck: " << table.deck << "\n";
    os << "Discard Pile: " << table.discardPile << "\n";
    os << "Trade Area: " << table.tradeArea << "\n";
    return os;
}
