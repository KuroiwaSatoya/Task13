#include "player.h"
#include <iostream>
using namespace std;

void Player::PlayTurn(Deck* deck) {
    while (true) {
        cout << "あなたのハンドは : " << endl;
        ShowHand();
        cout << "合計は : " << CalculateScore() << endl << endl;

        if (IsBusted()) {
            cout << "バーストしたのでディーラーの勝ちです。" << endl;
            return;
        }

        cout << "ヒットかスタンドか選択してください (ヒット : h,  スタンド : s) > ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            DrawCard(deck);
        }
        else if (choice == 's') {
            break;
        }
        else {
            cout << "エラー" << endl;
        }
        cout << endl;
    }
}