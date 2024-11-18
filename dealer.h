#pragma once
#include "player.h"

class Dealer : public Player {
public:
    void playTurn(Deck& deck);
};