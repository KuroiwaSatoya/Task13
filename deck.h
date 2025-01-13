#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Deck {
public:
    struct Card {
        // カードのマークをもつ
        enum Suit { HEART, DIAMOND, CLUB, SPADE };
        // カードの番号をもつ
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

        bool operator==(const Card& other) const;
    };

private:
    Card card[52];
    int cardDeal;

public:
    Deck();
    void Shuffle();
    Card getCard();
};