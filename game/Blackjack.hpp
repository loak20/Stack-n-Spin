#pragma once
#include "Game.hpp"
#include <string>
#include <vector>

struct Card {
    std::string rank;
    std::string suit;
};

class Blackjack : public Game {
public:
    Blackjack(const std::string& playerName, double initialBalance);
    void play(double& playerBalance) override;
    std::string getName() const override;
    int calculateHandValue(const std::vector<Card>& hand) const;
private:
    std::string playerName;
    double initialBalance;
    std::vector<Card> deck;
    void initializeDeck();
    void shuffleDeck();
    Card dealCard();
    void printHand(const std::vector<Card>& hand, bool hideFirstCard = false) const;
}; 