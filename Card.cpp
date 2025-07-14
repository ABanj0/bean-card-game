#include "Card.h"

// Implementations for Blue card
int Blue::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 4;
    case 2: return 6;
    case 3: return 8;
    case 4: return 10;
    default: return 0;
    }
}

std::string Blue::getName() const {
    return "Blue";
}

void Blue::print(std::ostream& out) const {
    out << 'B';
}

// Implementations for Chili card
int Chili::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 3;
    case 2: return 6;
    case 3: return 8;
    case 4: return 9;
    default: return 0;
    }
}

std::string Chili::getName() const {
    return "Chili";
}

void Chili::print(std::ostream& out) const {
    out << 'C';
}

// Implementations for Stink card
int Stink::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 3;
    case 2: return 5;
    case 3: return 7;
    case 4: return 8;
    default: return 0;
    }
}

std::string Stink::getName() const {
    return "Stink";
}

void Stink::print(std::ostream& out) const {
    out << 'S';
}

// Implementations for Green card
int Green::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 3;
    case 2: return 5;
    case 3: return 6;
    case 4: return 7;
    default: return 0;
    }
}

std::string Green::getName() const {
    return "Green";
}

void Green::print(std::ostream& out) const {
    out << 'G';
}

// Implementations for soy card
int soy::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 2;
    case 2: return 4;
    case 3: return 6;
    case 4: return 7;
    default: return 0;
    }
}

std::string soy::getName() const {
    return "soy";
}

void soy::print(std::ostream& out) const {
    out << 's';
}

// Implementations for black card
int black::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 2;
    case 2: return 4;
    case 3: return 5;
    case 4: return 6;
    default: return 0;
    }
}

std::string black::getName() const {
    return "black";
}

void black::print(std::ostream& out) const {
    out << 'b';
}

// Implementations for Red card
int Red::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    case 4: return 5;
    default: return 0;
    }
}

std::string Red::getName() const {
    return "Red";
}

void Red::print(std::ostream& out) const {
    out << 'R';
}

// Implementations for garden card
int garden::getCardsPerCoin(int coins) const {
    switch (coins) {
    case 1: return 0;
    case 2: return 2;
    case 3: return 3;
    case 4: return 0;
    default: return 0;
    }
}

std::string garden::getName() const {
    return "garden";
}

void garden::print(std::ostream& out) const {
    out << 'g';
}
