#include "TXLib.h"

void Door() {
    txSetColor(TX_BROWN);
    txSetFillColor(TX_BROWN);
    txRectangle(700, 500, 800, 700);
}

void FITH (HDC fire, int x, int y) {
     txTransparentBlt(txDC(), x, y, 150, 84, fire);
}


// struct {'тут переменые(и воид)'}; используй пж там типо онли названия переменых надо ну ты типо пон да


int main() {

    txCreateWindow (1200, 900);

    int x1 = 100; int vx = 15; int y1 = 100; int vy = 15;

    HDC fire = txLoadImage("fire in the hole.bmp");


    while (!GetAsyncKeyState (VK_ESCAPE)) {

        txSetFillColor (TX_GREY);
        txClear();
        txBegin;

        txSetColor (RGB(0, 255, 0));
        txSetFillColor (RGB(0, 255, 0));
        txRectangle(x1, y1, x1 + 50, y1 + 50);


        if (GetAsyncKeyState(VK_CONTROL)) {

            vx = 30;
            vy = 30;

        }


        if (GetAsyncKeyState('W')) {
            y1 -= vy;
        }

        else if (GetAsyncKeyState('A')) {
            x1 -= vx;
        }

        else if (GetAsyncKeyState('S')) {
            y1 += vy;
        }

        else if (GetAsyncKeyState('D')) {
            x1 += vx;
        }


        if (y1 < 0) {
            y1 = 0;
        }

        if (y1 > 900 - 50) {
            y1 = 900 - 50;
        }

        if (x1 < 0) {
            x1 = 0;
        }

        if (x1+50 > 1200) {
            x1 = 1200 - 50;
        }

        txEnd();
        txSleep(10);
    }

    txDeleteDC(fire);
    txDisableAutoPause();
    txTextCursor (false);
    return 0;
    }

