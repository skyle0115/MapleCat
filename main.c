#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>           //for random seed
#include "console_draw3.h"
#include "kb_input2.h"
#include "image.h"
#include "font.h"
#include "audio.h"
#include "mob.h"

extern Font *large_font;
extern Mob monster_attr[100];
extern Player p[3];

int main(){
    large_font = read_font("font.txt");

    init();
    addMob(1, 3);
    addMob(1, 3);
    addMob(1, 3);
    addMob(2, 2);
    int i = 100000, j, k;
    while(i--){
        clearScreen();

        test(int2string(p[1].blood), 0);
        test(int2string(p[2].blood), 1);

        for(j = 1; j <= 2; j++){
            for(k = p[j].count - 1; k >= 0; k--){
                switch(mobState(j, k)){
                case 1: //moving
                    moveMob(j, k);
                    break;
                case 2: //attacking
                    attackMob(j);
                    break;
                case 3: //left vibrating
                    moveMobLeft(j, k);
                    break;
                case 4: //right vibrating
                    moveMobRight(j, k);
                    break;
                case 5: //up vibrating
                    moveMobUp(j, k);
                    break;
                case 6: //down vibrating
                    moveMobDown(j, k);
                    break;
                case 7: //dying
                    dieMob(j);
                    break;
                }
            }
        }
        drawCmdWindow();
        Sleep(5);
    }
    return 0;
}
