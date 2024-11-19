#include "dealer.h"

void Dealer::playTurn(Deck* deck) {
    while (calculateScore() < 17 && !isBusted()) {
        drawCard(deck);
    }
}