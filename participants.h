#pragma once
#include "deck.h"

class Participants {
protected:
    Deck::Card hand[12];
    int handCount;

public:
    Participants();
    void drawCard(Deck* deck);
    void showHand(bool turnOver = true) const;
    int calculateScore() const;
    bool isBusted() const;
};