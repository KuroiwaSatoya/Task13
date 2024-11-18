#include "player.h"
#include <iostream>
using namespace std;

Player::Player() {
    handCount = 0;
}

void Player::drawCard(Deck& deck) {
    if (handCount < 52) {
        hand[handCount++] = deck.getCard();
    }
}

void Player::showHand(bool turnOver) const {
    for (int i = 0; i < handCount; ++i) {
        if (!turnOver && i > 0) {
            cout << "•š‚¹‚ç‚ê‚Ä‚¢‚Ü‚·B" << endl;
        }
        else {
            hand[i].printCard();
        }
    }
}

int Player::calculateScore() const {
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

bool Player::isBusted() const {
    return calculateScore() > 21;
}