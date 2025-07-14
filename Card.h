#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
public:
	virtual int getCardsPerCoin(int coins) const = 0;
	virtual std::string getName() const = 0;
	virtual void print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Card& card) {
		card.print(out);
		return out;
	}
};

class Blue : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class Chili : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class Stink : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class Green : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class soy : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class black : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class Red : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

class garden : public Card {
public:
	int getCardsPerCoin(int coins) const;
	std::string getName() const;
	void print(std::ostream& out) const;
};

#endif // CARD_H