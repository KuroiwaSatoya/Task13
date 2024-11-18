#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Deck {
public:
    struct Card {
        enum Suit { HEART, DIAMOND, CLUB, SPADE };
        enum Num {
            ACE = 1, TWO, THREE, FOUR, FIVE, SIX,
            SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
        };

        Suit suit;
        Num num;

        Card();
        void Initialize(Suit s, Num r);
        int getValue() const;
        void printCard() const;
    };

private:
    Card card[52];
    int cardDeal;

public:
    Deck();
    void Shuffle();
    Card getCard();
};