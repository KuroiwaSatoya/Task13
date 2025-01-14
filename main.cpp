#include <iostream>
#include "player.h"
#include "dealer.h"
#include "deck.h"

using namespace std;

int main() {
    srand((unsigned int)(time(NULL)));
    Deck deck;
    Player player[4]; // �v���C���[4�l�ɕύX
    string playerName[4] = { "�v���C���[1", "�v���C���[2", "�v���C���[3", "�v���C���[4" };
    Dealer dealer;

    for (int i = 0; i < 4; ++i) {
        player[i].drawCard(&deck);
        player[i].drawCard(&deck);
    }
    dealer.drawCard(&deck);
    dealer.drawCard(&deck);

    cout << "=======================" << endl << "�f�B�[���[�̎�D�� : " << endl;
    dealer.showHand(false);
    cout << "=======================" << endl << endl;

    cout << "=======================" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << playerName[i] << " �̎�D�� : " << endl;
        player[i].showHand(true);
        cout << "���v: " << player[i].calculateScore() << endl << endl;
    }
    cout << "=======================" << endl << endl;

    for (int i = 0; i < 4; ++i) {
        cout << "=== " << playerName[i] << " �̃^�[�� ===" << endl;
        player[i].playTurn(&deck);
        cout << endl << endl;

        if (player[i].isBusted()) {
            cout << playerName[i] << " �̓o�[�X�g���܂����B" << endl << endl;
        }
    }

    dealer.playTurn(&deck);

    cout << "�f�B�[���[�̃n���h�� : " << endl;
    dealer.showHand();
    cout << "�f�B�[���[�̍��v�� : " << dealer.calculateScore() << endl << endl;

    for (int i = 0; i < 4; ++i) {
        if (player[i].isBusted()) {
            cout << playerName[i] << " �̓o�[�X�g�������߁A�����ł��B" << endl;
        }
        else if (dealer.isBusted()) {
            cout << "�f�B�[���[���o�[�X�g�������߁A" << playerName[i] << " �̏����ł��I" << endl;
        }
        else {
            int playerScore = player[i].calculateScore();
            int dealerScore = dealer.calculateScore();

            if (playerScore > dealerScore) {
                cout << playerName[i] << " �̏����I" << endl;
            }
            else if (playerScore < dealerScore) {
                cout << playerName[i] << " �̕����I" << endl;
            }
            else {
                cout << playerName[i] << " �͈��������I" << endl;
            }
        }
        cout << endl;
    }
}
