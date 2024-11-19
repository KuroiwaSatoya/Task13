#pragma once
#include "participants.h"

class Dealer : public Participants {
public:
    void playTurn(Deck* deck);
};