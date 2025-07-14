#include "CardFactory.h"
CardFactory* CardFactory::factory = nullptr;

CardFactory::CardFactory() {
    for (int i = 0; i < 20; ++i) cardDeck.push_back(new Blue());
    for (int i = 0; i < 18; ++i) cardDeck.push_back(new Chili());
    for (int i = 0; i < 16; ++i) cardDeck.push_back(new Stink());
    for (int i = 0; i < 14; ++i) cardDeck.push_back(new Green());
    for (int i = 0; i < 12; ++i) cardDeck.push_back(new soy());
    for (int i = 0; i < 10; ++i) cardDeck.push_back(new black());
    for (int i = 0; i < 8; ++i) cardDeck.push_back(new Red());
    for (int i = 0; i < 6; ++i) cardDeck.push_back(new garden());
}

CardFactory* CardFactory::getFactory() {
    if (factory == nullptr) {
        factory = new CardFactory();
    }
    return factory;
}

Card* CardFactory::createCard(const std::string& name) {
    if (name == "Blue") return new Blue();
    else if (name == "Chili") return new Chili();
    else if (name == "Stink") return new Stink();
    else if (name == "Green") return new Green();
    else if (name == "soy") return new soy();
    else if (name == "black") return new black();
    else if (name == "Red") return new Red();
    else if (name == "garden") return new garden();
    return nullptr;  // Return nullptr if no matching card is found
}

Deck CardFactory::getDeck() const {
    Deck deck;

    // Copy all cards into the new deck
    for (Card* card : cardDeck) {
        deck.push_back(card);
    }

    std::random_shuffle(deck.begin(), deck.end());

    return deck;
}
