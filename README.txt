Overview
This project is a C++ implementation of a two-player bean-themed card game inspired by Bohnanza. Players collect and trade cards featuring eight types of beans, forming chains of identical beans to earn coins. The game emphasizes strategic trading, hand management, and chain building. The player with the most coins at the end wins.

The program models core game mechanics such as card dealing, hand sorting, trading, planting in chains, harvesting chains for coins, and managing visible and hidden cards according to the game rules.

Features
Two-player gameplay with alternating turns

Cards representing 8 distinct bean types, each with different scarcity

Sorted player hands with hidden cards

Up to three bean chains per player, each chain holding only one bean type

Trading system allowing players to exchange cards publicly

Draw deck and discard pile mechanics, with discard pile showing only the top card

Chain harvesting for coins based on chain size

Clear text-based user interface showing chains, trade areas, and discard pile

Enforcement of game rules including hand sorting, chain replacement, and turn phases

How to Play
Both players start with 5 cards each, and the remaining cards form the draw deck.

On a player’s turn:

They may add leftover trade cards from the previous turn to their chains or discard them.

They must play the top card from their hand onto a matching chain or replace an existing chain to start a new one.

Players can trade cards in a visible trade area with the opponent.

After trading, players draw cards from the deck to replenish their hands.

Any leftover trade cards remain for the next player’s turn.

Players strategically trade and plant beans to maximize coin gains.

The game ends when the draw deck is depleted, and the player with the most coins wins.