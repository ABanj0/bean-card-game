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

Sample Game Session
-------------------
Below is an example session demonstrating a typical turn, including the option to pause, save, and exit the game. This illustrates the main phases and player choices:

```
> Game started. Both players have 5 cards. Deck is shuffled.

> [Pause/Save/Exit Option]
Player 1 chooses to continue.

> [Table Display]
Player 1's Chains: [Red Bean x2], [Black-Eyed Bean x1]
Player 1's Hand: [hidden]
Trade Area: (empty)
Discard Pile: (Top: Cocoa Bean)
Deck: 40 cards remaining

> Player 1 draws the top card from the Deck.
Drew: Chili Bean

> Trade Area is empty. No beans to add to chains or discard.

> Player 1 plays the topmost card from their hand.
Played: Red Bean
Added to Red Bean chain (now x3)

> [Chain Harvest Check]
Red Bean chain not large enough to harvest. No coins earned.

> Player 1 chooses to play the next topmost card from their hand.
Played: Black-Eyed Bean
Added to Black-Eyed Bean chain (now x2)

> [Chain Harvest Check]
Black-Eyed Bean chain not large enough to harvest. No coins earned.

> Player 1 decides to discard a card from their hand.
Hand revealed: [Chili Bean, Stink Bean, Soy Bean]
Player 1 discards: Stink Bean
Discard Pile: (Top: Stink Bean)

> Player 1 draws three cards from the deck to the Trade Area.
Trade Area: [Wax Bean, Chili Bean, Blue Bean]

> [Discard Pile Check]
Top of discard pile (Stink Bean) does not match any card in Trade Area. No cards moved.

> For each card in the Trade Area:
Player 1 chooses to chain Wax Bean: No matching chain, skips.
Player 1 chooses to chain Chili Bean: No matching chain, skips.
Player 1 chooses to chain Blue Bean: No matching chain, skips.
Cards remain in Trade Area for next player.

> Player 1 draws two cards from Deck and adds them to the back of their hand.
Hand: [Chili Bean, Soy Bean, Wax Bean, Blue Bean]

> End of Player 1's turn. Next player's turn begins.

> [Pause/Save/Exit Option]
Player 2 chooses to pause and save the game.
Game state saved to file. Exiting...
```