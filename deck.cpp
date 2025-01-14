#include "Deck.h"

Deck::Card::Card() {
    suit = HEART;
    num = ACE;
}

void Deck::Card::Initialize(Suit s, Num r) {
    suit = s;
    num = r;
}

int Deck::Card::GetValue() const {
    if (num >= TEN) { return 10; }
    return num;
}

// カード情報を文字列として表示する
void Deck::Card::PrintCard() const {
    const char* suits[] = { "ハート", "ダイアモンド", "クラブ", "スペード" };
    const char* nums[] = { "エース", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                            "ジャック", "クイーン", "キング" };
    cout << suits[suit] << " の " << nums[num - 1] << endl;
}

// Cardクラス同士の==比較に対応する
bool Deck::Card::operator==(const Card& other) const {
    return (suit == other.suit && num == other.num);
}

Deck::Deck() {
    int count = 0;
    cardDeal = 0;
    for (int i = Card::HEART; i <= Card::SPADE; ++i) {
        for (int j = Card::ACE; j <= Card::KING; ++j) {
            card[count].Initialize(static_cast<Card::Suit>(i), static_cast<Card::Num>(j));
            count++;
        }
    }
    Shuffle();
}

void Deck::Shuffle() {
    for (int i = 51; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }
}

Deck::Card Deck::GetCard() {
    return card[cardDeal++];
}