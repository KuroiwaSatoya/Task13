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
        player[i].DrawCard(&deck);
        player[i].DrawCard(&deck);
    }
    dealer.DrawCard(&deck);
    dealer.DrawCard(&deck);

    cout << "=======================" << endl << "ディーラーの手札は : " << endl;
    dealer.ShowHand(false);
    cout << "=======================" << endl << endl;

    cout << "=======================" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << playerName[i] << " の手札は : " << endl;
        player[i].ShowHand(true);
        cout << "合計: " << player[i].CalculateScore() << endl << endl;
    }
    cout << "=======================" << endl << endl;

    for (int i = 0; i < 4; ++i) {
        cout << "=== " << playerName[i] << " のターン ===" << endl;
        player[i].PlayTurn(&deck);
        cout << endl << endl;

        if (player[i].IsBusted()) {
            cout << playerName[i] << " はバーストしました。" << endl << endl;
        }
    }

    dealer.PlayTurn(&deck);

    cout << "ディーラーのハンドは : " << endl;
    dealer.ShowHand();
    cout << "ディーラーの合計は : " << dealer.CalculateScore() << endl << endl;

    for (int i = 0; i < 4; ++i) {
        if (player[i].IsBusted()) {
            cout << playerName[i] << " はバーストしたため、負けです。" << endl;
        }
        else if (dealer.IsBusted()) {
            cout << "ディーラーがバーストしたため、" << playerName[i] << " の勝ちです！" << endl;
        }
        else {
            int playerScore = player[i].CalculateScore();
            int dealerScore = dealer.CalculateScore();

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
