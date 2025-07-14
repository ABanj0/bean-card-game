#include <iostream>
#include <sstream>
#include "CardFactory.h"
#include "Table.h"

int main() {
    std::cout << "Starting a new Game!" << std::endl;
    std::string n1, n2;
    std::cout << "Player 1: What is your name?" << std::endl;
    std::cin >> n1;
    std::cout << "Player 2: What is your name?" << std::endl;
    std::cin >> n2;
    std::stringstream ss;
    ss << n1 << " ";
    ss << n2 << " ";
    CardFactory* factory = CardFactory::getFactory();
    Table table(ss, factory);
    table.setDeck(factory->getDeck());  // Ensure the deck is freshly loaded from the factory
    for (int i = 0; i < 5; i++) {
        table.player1.getPlayersHand()->operator+=(table.deck.draw());
        table.player2.getPlayersHand()->operator+=(table.deck.draw());
    }


    while (!table.deck.empty()) {
        for (auto& player : { &table.player1, &table.player2 }) {
			std::cout << "Current player: " << player->getName() << std::endl;
            std::cout << "Table's current state:" << std::endl;
            std::cout << "=======================================" << std::endl;
			std::cout << table << std::endl;
            std::cout << "=======================================" << std::endl;

            if (player->getNumCoins() >= 3 && player->getMaxNumChains() == 2) {
                std::cout << "You have " << player->getNumCoins() << " coins and " << player->getMaxNumChains() << " chains." << std::endl;
                std::cout << "Do you want to buy a third chain for 3 coins? (y/n)" << std::endl;
                char buyChainResponse;
                std::cin >> buyChainResponse;
                if (buyChainResponse == 'y' || buyChainResponse == 'Y') {
                    player->buyThirdChain();
                    std::cout << "You have purchased a third chain slot." << std::endl;
                }
            }

			std::cout << "You drew the top card of the deck which was: " << *table.deck.back() << std::endl;
            player->getPlayersHand()->operator+=(table.deck.draw());
			std::cout << "Your hand is now: " << *player->getPlayersHand() << std::endl;
            if (table.tradeArea.numCards() != 0) {
                std::cout << "The trade area has: " << table.tradeArea << std::endl;
                std::cout << "Would you like to attempt to chain all cards from the trade area? (y/n)" << std::endl;
                char response;
                std::cin >> response;
                if (response == 'y') {
                    while (table.tradeArea.numCards() > 0) {
                        Card* card = table.tradeArea.trade(table.tradeArea.top()->getName());
                        bool chained = false;
                        for (auto& chain : player->getPlayersChains()) {
                            try {
                                chain->addCard(card);
                                std::cout << "Card added to existing chain." << std::endl;
                                chained = true;
                                break;
                            }
                            catch (const std::exception& e) {
                                continue;
                            }
                        }

                        if (!chained && player->getNumChains() < player->getMaxNumChains()) {
                            std::shared_ptr<Chain_Base> newChain = player->createChainForCard(card);
                            newChain->addCard(card);
                            player->getPlayersChains().push_back(newChain);
                            std::cout << "New chain created and card added." << std::endl;
                        }
                        else if (!chained) {
                            std::cout << "No available chain slots to add new card chain, discarding card." << std::endl;
                            table.discardPile += card;
                        }
                    }
                }
                else {
                    while (table.tradeArea.numCards() > 0) {
                        Card* card = table.tradeArea.trade(table.tradeArea.top()->getName());
                        table.discardPile += card;
                        std::cout << "Discarding card from trade area: " << card->getName() << std::endl;
                    }
                }
            }

            std::cout << player << std::endl;
            int step2 = 2;
            while (step2 > 0) {
                Card* topCard = player->getPlayersHand()->top();
                std::cout << "Top card from hand that will be played is: " << *topCard << std::endl;

                bool cardChained = false;
                for (auto& chain : player->getPlayersChains()) {
                    try {
                        chain->addCard(topCard);
                        std::cout << "Card added to existing chain." << std::endl;
                        cardChained = true;
                        break;
                    }
                    catch (const std::exception& e) {
                        continue; 
                    }
                }

                if (!cardChained) {
                    if (player->getNumChains() < player->getMaxNumChains()) { 
                        std::shared_ptr<Chain_Base> newChain = player->createChainForCard(topCard);
                        newChain->addCard(topCard);
                        player->getPlayersChains().push_back(newChain);
                        std::cout << "New chain created for the card." << std::endl;
                    }
                    else {  // If there's no space for a new chain
                        std::cout << "No available slots to create a new chain. You need to sell an existing chain." << std::endl;
                        std::cout << "Here are your current chains:" << std::endl;
                        int index = 1;
                        for (auto& chain : player->getPlayersChains()) {
                            std::cout << index++ << ". " << *chain << std::endl;
                        }
                        std::cout << "Select the number of the chain you want to sell: ";
                        int chainIndex;
                        std::cin >> chainIndex;

                        if (chainIndex > 0 && chainIndex <= player->getPlayersChains().size()) {
                            auto it = player->getPlayersChains().begin();
                            std::advance(it, chainIndex - 1);
                            int coins = (*it)->sell();
                            player->operator+=(coins);
                            std::cout << "Sold chain " << chainIndex << " for " << coins << " coins." << std::endl;
                            player->getPlayersChains().erase(it);
                            std::shared_ptr<Chain_Base> newChain = player->createChainForCard(topCard);
                            newChain->addCard(topCard);
                            player->getPlayersChains().push_back(newChain);
                            std::cout << "New chain created for the card after selling the old one." << std::endl;
                        }
                        else {
                            std::cout << "Invalid chain selection. No chain sold or created." << std::endl;
                        }
                    }
                }

                player->getPlayersHand()->play();

				std::cout << "Player's current state:\n" << *player << std::endl;
                if (step2 == 2) {
                    std::cout << "Would you like to continue playing cards from your hand? (y/n)" << std::endl;
                    char response;
                    std::cin >> response;
                    if (response == 'y' || response == 'Y') {
                        step2 -= 1;
                    }
                    else if (response == 'n' || response == 'N') {
                        step2 = 0;
                    }
				}
				else {
					step2 = 0;
				}
            }

            std::cout << player << std::endl;

            std::cout << "Do you want to display your full hand and discard a card? (y/n)" << std::endl;
            char displayResponse;
            std::cin >> displayResponse;
            if (displayResponse == 'y' || displayResponse == 'Y') {
                std::cout << "Your full hand: " << *player->getPlayersHand() << std::endl;
                std::cout << "Select the position of the card to discard (1 to " << player->getPlayersHand()->size() << "): ";
                int position;
                std::cin >> position;
                if (position > 0 && position <= player->getPlayersHand()->size()) {
                    Card* discardedCard = player->getPlayersHand()->play(position - 1); 
                    table.discardPile += discardedCard;
                    std::cout << "You discarded: " << *discardedCard << std::endl;
                }
                else {
                    std::cout << "Invalid card position. No card discarded." << std::endl;
                }
            }

            std::cout << player << std::endl;

            for (int i = 0; i < 3; i++) {
                if (!table.deck.empty()) {
                    Card* card = table.deck.draw();
                    table.tradeArea += card;
                    std::cout << "Placed " << card->getName() << " in the trade area." << std::endl;
                }
            }

            std::cout << player << std::endl;

			std::cout << "Checking for matches between the trade area and the discard pile." << std::endl;
			std::cout << "Trade area: " << table.tradeArea << std::endl;
			std::cout << "Discard pile: " << table.discardPile << std::endl;
            while (!table.discardPile.isEmpty() && table.tradeArea.legal(table.discardPile.top())) {
                Card* card = table.discardPile.pickUp();
                table.tradeArea += card;
                std::cout << "Moved " << card->getName() << " from discard pile to trade area due to a match." << std::endl;
            }

            while (!table.tradeArea.isEmpty()) {
                std::cout << "Would you like to chain any card from the trade area? (y/n)" << std::endl;
                char response;
                std::cin >> response;
                if (response == 'y' || response == 'Y') {
                    std::cout << "Which card would you like to chain?" << std::endl;
                    std::string cardName;
                    std::cin >> cardName;
                    if (table.tradeArea.legal(factory->createCard(cardName))) {
                        Card* card = table.tradeArea.trade(cardName);
                        bool chained = false;
                        for (auto& chain : player->getPlayersChains()) {
                            try {
                                chain->addCard(card);
                                std::cout << "Card added to existing chain." << std::endl;
                                chained = true;
                                break;
                            }
                            catch (const std::exception& e) {
                                continue;
                            }
                        }

                        if (!chained) {
                            if (player->getNumChains() < player->getMaxNumChains()) {
                                std::shared_ptr<Chain_Base> newChain = player->createChainForCard(card);
                                newChain->addCard(card);
                                player->getPlayersChains().push_back(newChain);
                                std::cout << "New chain created and card added." << std::endl;
                            }
                            else {
                                std::cout << "No available chain slots to add new card chain, you may sell a chain." << std::endl;
                                std::cout << "Would you like to sell a chain to make room? (y/n)" << std::endl;
                                std::cin >> response;
                                if (response == 'y' || response == 'Y') {
                                    std::cout << "Here are your current chains:" << std::endl;
                                    int index = 1;
                                    for (auto& chain : player->getPlayersChains()) {
                                        std::cout << index++ << ". " << *chain << std::endl;
                                    }
                                    std::cout << "Select the number of the chain you want to sell: ";
                                    int chainIndex;
                                    std::cin >> chainIndex;

                                    if (chainIndex > 0 && chainIndex <= player->getPlayersChains().size()) {
                                        auto it = player->getPlayersChains().begin();
                                        std::advance(it, chainIndex - 1);
                                        int coins = (*it)->sell();
                                        player->operator+=(coins);
                                        std::cout << "Sold chain " << chainIndex << " for " << coins << " coins." << std::endl;
                                        player->getPlayersChains().erase(it);
                                        std::shared_ptr<Chain_Base> newChain = player->createChainForCard(card);
                                        newChain->addCard(card);
                                        player->getPlayersChains().push_back(newChain);
                                        std::cout << "New chain created for the card after selling the old one." << std::endl;
                                    }
                                    else {
                                        std::cout << "Invalid chain selection. No chain sold or created." << std::endl;
                                        table.tradeArea += card;
                                    }
                                }
                                else {
                                    std::cout << "Card will remain in the trade area." << std::endl;
                                    table.tradeArea += card;
                                }
                            }
                        }
                    }
                    else {
                        std::cout << "Card does not exist in the trade area or cannot be chained. Please try again." << std::endl;
                    }
                }
                else {
                    std::cout << "No more cards will be chained. Remaining cards will stay for the next player." << std::endl;
                    break;
                }
            }
        }
    }

    std::string winner;
    if (table.win(winner)) {
        if (winner == "Draw") {
            std::cout << "The game is a draw!" << std::endl;
        }
        else {
            std::cout << "The winner is: " << winner << "!" << std::endl;
        }
    }

    return 0;
}
