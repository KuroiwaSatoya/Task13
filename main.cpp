#include <iostream>
#include "player.h"
#include "dealer.h"
#include "deck.h"

using namespace std;

int main() {
    srand((unsigned int)(time(NULL)));
    Deck deck;
    Player player[4]; // プレイヤー4人に変更
    string playerName[4] = { "プレイヤー1", "プレイヤー2", "プレイヤー3", "プレイヤー4" };
    Dealer dealer;

    for (int i = 0; i < 4; ++i) {
        player[i].drawCard(&deck);
        player[i].drawCard(&deck);
    }
    dealer.drawCard(&deck);
    dealer.drawCard(&deck);

    cout << "=======================" << endl << "ディーラーの手札は : " << endl;
    dealer.showHand(false);
    cout << "=======================" << endl << endl;

    cout << "=======================" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << playerName[i] << " の手札は : " << endl;
        player[i].showHand(true);
        cout << "合計: " << player[i].calculateScore() << endl << endl;
    }
    cout << "=======================" << endl << endl;

    for (int i = 0; i < 4; ++i) {
        cout << "=== " << playerName[i] << " のターン ===" << endl;
        player[i].playTurn(&deck);
        cout << endl << endl;

        if (player[i].isBusted()) {
            cout << playerName[i] << " はバーストしました。" << endl << endl;
        }
    }

    dealer.playTurn(&deck);

    cout << "ディーラーのハンドは : " << endl;
    dealer.showHand();
    cout << "ディーラーの合計は : " << dealer.calculateScore() << endl << endl;

    for (int i = 0; i < 4; ++i) {
        if (player[i].isBusted()) {
            cout << playerName[i] << " はバーストしたため、負けです。" << endl;
        }
        else if (dealer.isBusted()) {
            cout << "ディーラーがバーストしたため、" << playerName[i] << " の勝ちです！" << endl;
        }
        else {
            int playerScore = player[i].calculateScore();
            int dealerScore = dealer.calculateScore();

            if (playerScore > dealerScore) {
                cout << playerName[i] << " の勝ち！" << endl;
            }
            else if (playerScore < dealerScore) {
                cout << playerName[i] << " の負け！" << endl;
            }
            else {
                cout << playerName[i] << " は引き分け！" << endl;
            }
        }
        cout << endl;
    }
}
