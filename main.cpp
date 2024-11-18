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

    player.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);
    dealer.drawCard(deck);

    cout << "�f�B�[���[�̎�D�� : " << endl;
    dealer.showHand(false);
    cout << endl;

    while (true) {
        cout << "���Ȃ��̃n���h�� : " << endl;
        player.showHand();
        cout << "���v�� : " << player.calculateScore() << endl << endl;

        if (player.isBusted()) {
            cout << "�o�[�X�g�����̂Ńf�B�[���[�̏����ł��B" << endl;
            return 0;
        }

        cout << "�q�b�g���X�^���h���I�����Ă������� (�q�b�g : h,  �X�^���h : s) > ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            player.drawCard(deck);
        }
        else if (choice == 's') {
            break;
        }
        else {
            cout << "�G���[" << endl;
        }
        cout << endl;
    }

    dealer.playTurn(deck);

    cout << "�f�B�[���[�̃n���h�� : " << endl;
    dealer.showHand();
    cout << "�f�B�[���[�̍��v�� : " << dealer.calculateScore() << endl << endl;

    if (dealer.isBusted()) {
        cout << "�f�B�[���[���o�[�X�g���܂����B���Ȃ��̏����ł��I" << endl;
    }
    else {
        int playerScore = player.calculateScore();
        int dealerScore = dealer.calculateScore();

        if (playerScore > dealerScore) {
            cout << "�����I" << endl;
        }
        else if (playerScore < dealerScore) {
            cout << "�����I" << endl;
        }
        else {
            cout << "���������I" << endl;
        }
    }
}
