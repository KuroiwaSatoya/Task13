#pragma once
#include "deck.h"

class Player {
protected:
    Deck::Card hand[52];
    int handCount;

public:
    Player();
    void drawCard(Deck& deck);
    void showHand(bool turnOver = true) const;
    int calculateScore() const;
    bool isBusted() const;
};