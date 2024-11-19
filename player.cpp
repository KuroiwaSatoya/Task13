#include "player.h"
#include <iostream>
using namespace std;

void Player::playTurn(Deck* deck) {
    while (true) {
        cout << "���Ȃ��̃n���h�� : " << endl;
        showHand();
        cout << "���v�� : " << calculateScore() << endl << endl;

        if (isBusted()) {
            cout << "�o�[�X�g�����̂Ńf�B�[���[�̏����ł��B" << endl;
            return;
        }

        cout << "�q�b�g���X�^���h���I�����Ă������� (�q�b�g : h,  �X�^���h : s) > ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            drawCard(deck);
        }
        else if (choice == 's') {
            break;
        }
        else {
            cout << "�G���[" << endl;
        }
        cout << endl;
    }
}