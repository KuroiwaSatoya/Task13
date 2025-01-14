#pragma once
#include "participants.h"

class Dealer : public Participants {
public:
    void PlayTurn(Deck* deck);
};