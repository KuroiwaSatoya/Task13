#include <iostream>
#include "player.h"
#include "dealer.h"
#include "deck.h"

using namespace std;

int main() {
    srand((unsigned int)(time(NULL)));
    Deck deck;
    Player player;
    Dealer dealer;

    player.drawCard(&deck);
    player.drawCard(&deck);
    dealer.drawCard(&deck);
    dealer.drawCard(&deck);

    cout << "ディーラーの手札は : " << endl;
    dealer.showHand(false);
    cout << endl;

    player.playTurn(&deck);

    if (player.isBusted()) {
        return 0;
    }

    dealer.playTurn(&deck);

    cout << "ディーラーのハンドは : " << endl;
    dealer.showHand();
    cout << "ディーラーの合計は : " << dealer.calculateScore() << endl << endl;

    if (dealer.isBusted()) {
        cout << "ディーラーがバーストしました。あなたの勝ちです！" << endl;
    }
    else {
        int playerScore = player.calculateScore();
        int dealerScore = dealer.calculateScore();

        if (playerScore > dealerScore) {
            cout << "勝ち！" << endl;
        }
        else if (playerScore < dealerScore) {
            cout << "負け！" << endl;
        }
        else {
            cout << "引き分け！" << endl;
        }
    }
}
