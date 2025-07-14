#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include "Card.h"
#include "CardFactory.h"

class Chain_Base {
public:
    virtual int sell() const = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual void addCard(Card* card) = 0;
    virtual bool isEmpty() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Chain_Base& chain) {
        chain.print(os);
        return os;
    }
};

template <typename T>
class Chain : public Chain_Base {
public:
    Chain() = default;
    // Constructor
    Chain(std::istream& in, const CardFactory* cardFactory) {
        std::string cardName;
        while (in >> cardName) {
            Card* card = cardFactory->createCard(cardName);
            T* cardToAdd = dynamic_cast<T*>(card);
            if (!cardToAdd) {
                throw std::runtime_error("IllegalType");
            }
            cards.push_back(cardToAdd);
        }
    }

    // Adding a card to the chain
    void addCard(Card* card) override {
        T* specificCard = dynamic_cast<T*>(card);
        if (!specificCard) {
            throw std::runtime_error("Attempted to add illegal card type to Chain of " + std::string(typeid(T).name()));
        }
        cards.push_back(specificCard);
    }

    // Checking if the chain is empty
    bool isEmpty() const override {
        return cards.empty();
    }

    // Adds cards to the Chain
    Chain<T>& operator+=(Card* card) {
        T* cardToAdd = dynamic_cast<T*>(card);
        if (!cardToAdd) {
            throw std::runtime_error("IllegalType");
        }
        cards.push_back(cardToAdd);
        return *this;
    }

    // Sells the cards in the chain
    int sell() const override {
        if (cards.empty()) return 0;

        int numCards = cards.size();
        int coins = 0;
        for (int i = 4; i >= 1; --i) {
            while (numCards >= cards.front()->getCardsPerCoin(i)) {
                numCards -= cards.front()->getCardsPerCoin(i);
                coins += i;
            }
        }
        return coins;
    }

    // Prints the cards in the chain
    void print(std::ostream& out) const override {
        if (!cards.empty()) {
            out << cards.front()->getName() << " ";
            for (const auto& card : cards) {
                card->print(out);
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Chain<T>& chain) {
        chain.print(os);
        return os;
    }

private:
    std::vector<T*> cards;
};

#endif // CHAIN_H