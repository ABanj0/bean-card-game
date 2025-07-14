// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include "Chain.h"
#include "CardFactory.h"
#include "Hand.h"

class NotEnoughCoins : public std::exception {
public:
    const char* what() const noexcept override {
        return "Not enough coins to buy a third chain.";
    }
};

class Player {
private:
    std::string name;
    int coins = 0;
    int maxNumChains = 2;
    std::vector<std::shared_ptr<Chain_Base>> chains;
    Hand* hand;

public:
	Player() = default;
    // Constructor that creates a Player with a given name
    Player(const std::string& playerName);

    std::shared_ptr<Chain_Base> createChainForCard(Card* card);

    // Constructor to reconstruct the Player from an input stream
    Player(std::istream& in, const CardFactory* cardFactory);

    // Get the name of the player
    std::string getName() const;

    // Get the number of coins currently held by the player
    int getNumCoins() const;

    // Add a number of coins
    Player& operator+=(int coinsToAdd);

    // Returns either 2 or 3
    int getMaxNumChains() const;

    // Returns the number of non-zero chains
    int getNumChains() const;

    // Returns the chain at position i
    Chain_Base& operator[](int i) const;

    // Adds an empty third chain to the player for three coins
    void buyThirdChain();

    // Prints the top card of the player's hand or all of the player's hand
    void printHand(std::ostream& os, bool all) const;

    // Friend function to print a Player to an ostream
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    std::vector<std::shared_ptr<Chain_Base>>& getPlayersChains() {
		return chains;
    }

    Hand* getPlayersHand() {
        return hand;
    }
};

#endif // PLAYER_H