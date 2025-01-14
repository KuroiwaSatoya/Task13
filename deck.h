#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Deck {
public:
    struct Card {
    private:
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
        int GetValue() const;
        void PrintCard() const;

        bool operator==(const Card& other) const;
    };

private:
    static const int MAX_CARDS = 52;
    Card card[MAX_CARDS];
    int cardDeal;

public:
    Deck();
    void Shuffle();
    Card GetCard();
};