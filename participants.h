#pragma once
#include "deck.h"

class Participants {
protected:
    Deck::Card hand[12];
    int handCount;

public:
    Participants();
    void DrawCard(Deck* deck);
    void ShowHand(bool turnOver = true) const;
    int CalculateScore() const;
    bool IsBusted() const;
};