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
        player[i].DrawCard(&deck);
        player[i].DrawCard(&deck);
    }
    dealer.DrawCard(&deck);
    dealer.DrawCard(&deck);

    cout << "=======================" << endl << "�f�B�[���[�̎�D�� : " << endl;
    dealer.ShowHand(false);
    cout << "=======================" << endl << endl;

    cout << "=======================" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << playerName[i] << " �̎�D�� : " << endl;
        player[i].ShowHand(true);
        cout << "���v: " << player[i].CalculateScore() << endl << endl;
    }
    cout << "=======================" << endl << endl;

    for (int i = 0; i < 4; ++i) {
        cout << "=== " << playerName[i] << " �̃^�[�� ===" << endl;
        player[i].PlayTurn(&deck);
        cout << endl << endl;

        if (player[i].IsBusted()) {
            cout << playerName[i] << " �̓o�[�X�g���܂����B" << endl << endl;
        }
    }

    dealer.PlayTurn(&deck);

    cout << "�f�B�[���[�̃n���h�� : " << endl;
    dealer.ShowHand();
    cout << "�f�B�[���[�̍��v�� : " << dealer.CalculateScore() << endl << endl;

    for (int i = 0; i < 4; ++i) {
        if (player[i].IsBusted()) {
            cout << playerName[i] << " �̓o�[�X�g�������߁A�����ł��B" << endl;
        }
        else if (dealer.IsBusted()) {
            cout << "�f�B�[���[���o�[�X�g�������߁A" << playerName[i] << " �̏����ł��I" << endl;
        }
        else {
            int playerScore = player[i].CalculateScore();
            int dealerScore = dealer.CalculateScore();

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
