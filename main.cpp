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

    cout << "�f�B�[���[�̎�D�� : " << endl;
    dealer.showHand(false);
    cout << endl;

    player.playTurn(&deck);

    if (player.isBusted()) {
        return 0;
    }

    dealer.playTurn(&deck);

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
