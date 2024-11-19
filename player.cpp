#include "player.h"
#include <iostream>
using namespace std;

void Player::playTurn(Deck* deck) {
    while (true) {
        cout << "あなたのハンドは : " << endl;
        showHand();
        cout << "合計は : " << calculateScore() << endl << endl;

        if (isBusted()) {
            cout << "バーストしたのでディーラーの勝ちです。" << endl;
            return;
        }

        cout << "ヒットかスタンドか選択してください (ヒット : h,  スタンド : s) > ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            drawCard(deck);
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