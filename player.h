#pragma once
#include "participants.h"

class Player : public Participants {
public:
    void playTurn(Deck* deck);
};