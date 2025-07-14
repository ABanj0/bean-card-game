#include "Player.h"
#include "Chain.h"

// Constructor that creates a Player with a given name
Player::Player(const std::string& playerName) : name(playerName), coins(0), maxNumChains(2), hand(new Hand()) {}

// Constructor to reconstruct the Player from an input stream
Player::Player(std::istream& in, const CardFactory* cardFactory) {
    in >> name;
    hand = new Hand(in, cardFactory);
}

// Get the name of the player
std::string Player::getName() const {
    return name;
}

// Get the number of coins currently held by the player
int Player::getNumCoins() const {
    return coins;
}

// Add a number of coins
Player& Player::operator+=(int coinsToAdd) {
    coins += coinsToAdd;
    return *this;
}

// Returns either 2 or 3
int Player::getMaxNumChains() const {
    return maxNumChains;
}
int Player::getNumChains() const {
    int count = 0;
    for (const auto& chain : chains) {
        if (!chain->isEmpty()) {
            count++;
        }
    }
    return count;
}

// Returns the chain at position i
Chain_Base& Player::operator[](int i) const{
    return *chains[i];
}

// Adds an empty third chain to the player for three coins
void Player::buyThirdChain() {
    if (coins < 3) {
        throw NotEnoughCoins();
    }
    if (maxNumChains < 3) {
        coins -= 3;
        maxNumChains++;
    }
}

// Prints the top card of the player's hand or all of the player's hand
void Player::printHand(std::ostream& os, bool all) const{
    if (all) {
        os << *hand;
    } else {
        os << hand->top();
    }
}

std::shared_ptr<Chain_Base> Player::createChainForCard(Card* card) {
    if (card->getName() == "Blue") {
        return std::make_shared<Chain<Blue>>();
    }
    else if (card->getName() == "Red") {
        return std::make_shared<Chain<Red>>();
    }
    else if (card->getName() == "Chili") {
        return std::make_shared<Chain<Chili>>();
    }
    else if (card->getName() == "Stink") {
        return std::make_shared<Chain<Stink>>();
    }
    else if (card->getName() == "Green") {
        return std::make_shared<Chain<Green>>();
    }
    else if (card->getName() == "soy") {
        return std::make_shared<Chain<soy>>();
    }
    else if (card->getName() == "black") {
        return std::make_shared<Chain<black>>();
    }
    else if (card->getName() == "garden") {
        return std::make_shared<Chain<garden>>();
    }
    else {
        throw std::runtime_error("Unsupported card type for chaining");
    }
}


// Friend function to print a Player to an ostream
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.name << " " << player.getNumCoins() << " coins\n";
    for (const auto& chain : player.chains) {
        if (!chain->isEmpty()) {
            os << *chain << "\n";
        }
    }
    return os;
}
