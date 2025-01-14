#include "player.h"
#include <iostream>
using namespace std;

void Player::PlayTurn(Deck* deck) {
    while (true) {
        cout << "���Ȃ��̃n���h�� : " << endl;
        ShowHand();
        cout << "���v�� : " << CalculateScore() << endl << endl;

        if (IsBusted()) {
            cout << "�o�[�X�g�����̂Ńf�B�[���[�̏����ł��B" << endl;
            return;
        }

        cout << "�q�b�g���X�^���h���I�����Ă������� (�q�b�g : h,  �X�^���h : s) > ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            DrawCard(deck);
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