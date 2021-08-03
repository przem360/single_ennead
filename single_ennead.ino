#include "jaylib.h"
#include "utils.h"

#include "card.h"
#include "card_data.h"

#include "game.h"

Jaylib jay;

void setup() {
    jay.boot();
    jay.invert(1);
    jay.clear();

}

Game game = Game();

void loop() {
    if(!jay.nextFrame()) return;

    //
    jay.pollButtons();
    jay.clear();

    /*
    if(jay.justPressed(A_BUTTON) || jay.justPressed(B_BUTTON)) {
    }
    */

    if(jay.justPressed(UP_BUTTON)) {
        game.selection --;
    }

    if(jay.justPressed(DOWN_BUTTON)) {
        game.selection ++;
    }

    /*
    CARDS[0].print(jay, 36, 1, 0);
    CARDS[1].print(jay, 55, 1, 1);
    CARDS[2].print(jay, 74, 1, 0);

    CARDS[3].print(jay, 36, 22, 1);
    CARDS[4].print(jay, 55, 22, 0);
    CARDS[5].print(jay, 74, 22, 0);

    CARDS[6].print(jay, 36, 43, 0);
    CARDS[7].print(jay, 55, 43, 0);
    CARDS[8].print(jay, 74, 43, 0);
    */

    game.board[0][0] = {1,0};
    game.board[0][1] = {2,1};
    game.board[0][2] = {3,1};

    //game.board[1][0] = {4,0};
    game.board[1][1] = {5,0};
    game.board[1][2] = {6,1};

    game.board[2][0] = {7,0};
    game.board[2][1] = {8,1};
    game.board[2][2] = {9,0};

    game.cards[0][0] = 1;
    game.cards[0][1] = 2;
    //game.cards[0][2] = 3;
    game.cards[0][3] = 4;
    game.cards[0][4] = 5;

    game.cards[1][0] = 1;
    game.cards[1][1] = 1;
    game.cards[1][2] = 1;
    game.cards[1][3] = 1;
    game.cards[1][4] = 1;

    game.scores[0] = 3;
    game.scores[1] = 2;

    game.turn = 1;

    game.print(jay);

    /*
    for(int i =0; i < 2000; i++) {
        jay.drawFastVLine(102, 24, 8, 1);
        jay.drawFastVLine(102, 24, 8, 0);

        jay.drawFastVLine(101, 24, 28, 1);
        jay.drawFastVLine(101, 24, 26, 0);

        jay.drawFastVLine(100, 22, 28, 1);
        jay.drawFastVLine(100, 23, 26, 0);
    }
    */

    jay.smallPrint(99, 56, itoa(jay.cpuLoad()), 1);

    jay.display();
}

// vim:syntax=c
