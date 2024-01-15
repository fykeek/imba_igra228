#include "TXLib.h"

void FITH (HDC fire, int x, int y) {
     txTransparentBlt(txDC(), x, y, 150, 84, fire);
}

int main() {

    txCreateWindow (1200, 800);

    int x1 = 100; int vx = 15; int y1 = 100; int vy = 15;

    HDC fire = txLoadImage("fire in the hole.bmp");

    while (!GetAsyncKeyState (VK_ESCAPE)) {

        txSetFillColor (TX_BLACK);
        txClear();
        txBegin;

        FITH(fire, x1, y1);

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

        if (y1 > 800 - 84) {
            y1 = 800 - 84;
        }

        if (x1 < 0) {
            x1 = 0;
        }

        if (x1+150 > 1200) {
            x1 = 1200 - 150;
        }

        txEnd();
        txSleep(10);
    }

    txDeleteDC(fire);
    txDisableAutoPause();
    txTextCursor (false);
    return 0;
    }

