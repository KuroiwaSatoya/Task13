#include "participants.h"
#include <iostream>
using namespace std;

Participants::Participants() {
    handCount = 0;
}

void Participants::drawCard(Deck* deck) { // ポインタを使用
    if (handCount < 12) {
        hand[handCount++] = deck->getCard();
    }
}

void Participants::showHand(bool turnOver) const {
    for (int i = 0; i < handCount; ++i) {
        if (!turnOver && i > 0) {
            cout << "伏せられています。" << endl;
        }
        else {
            hand[i].printCard();
        }
    }
}

int Participants::calculateScore() const {
    int score = 0, aceCount = 0;
    for (int i = 0; i < handCount; ++i) {
        int value = hand[i].getValue();
        score += value;
        if (value == 1) aceCount++;
    }

    while (score <= 11 && aceCount > 0) {
        score += 10;
        aceCount--;
    }

    return score;
}

bool Participants::isBusted() const {
    return calculateScore() > 21;
}