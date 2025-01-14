#include "participants.h"
#include <iostream>
using namespace std;

Participants::Participants() {
    handCount = 0;
}

void Participants::DrawCard(Deck* deck) {
    if (handCount < 12) {
        hand[handCount++] = deck->GetCard();
    }
}

void Participants::ShowHand(bool turnOver) const {
    for (int i = 0; i < handCount; ++i) {
        if (!turnOver && i > 0) {
            cout << "•š‚¹‚ç‚ê‚Ä‚¢‚Ü‚·B" << endl;
        }
        else {
            hand[i].PrintCard();
        }
    }
}

int Participants::CalculateScore() const {
    int score = 0, aceCount = 0;
    for (int i = 0; i < handCount; ++i) {
        int value = hand[i].GetValue();
        score += value;
        if (value == 1) aceCount++;
    }

    while (score <= 11 && aceCount > 0) {
        score += 10;
        aceCount--;
    }

    return score;
}

bool Participants::IsBusted() const {
    return CalculateScore() > 21;
}