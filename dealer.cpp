#include "dealer.h"

void Dealer::PlayTurn(Deck* deck) {
    while (CalculateScore() < 17 && !IsBusted()) {
        DrawCard(deck);
    }
}