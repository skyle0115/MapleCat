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

#define MOB_MAX_COUNT 5

Font *large_font;

typedef struct{
    Image *img_l, *img_r;
    int cost;
    int w, h;
    int blood;
    int attack;
    int defense;
    int move_speed;
    int atk_speed;
    int money;
    Image *img;
    int move_unit;
    int x, y;
    int wall, floor;
    int hp;
    int harm;
    int move_flag;
    int atk_flag;
    int ver_flag;
    int hor_flag;
    int state;
} Mob;

typedef struct{
    int money;
    int blood;
    Mob monster[MOB_MAX_COUNT];
    int front;
    int count;
    int border;
} Player;

Mob monster_attr[100];
Player p[3];

int showMob1_x,
    showMob1_y,
    showMob2_x,
    showMob2_y;

char* int2string(int value){
    char string[10];
    sprintf(string, "%d", value);
    return string;
}

int float2int(float f){
    return (int) (f + 0.5);
}

int randHarm(int harm){
    return float2int(((rand()%41)+80)/100.0*harm);
}

int offset(int v){
    return ((rand()%(v*2+1)) -v);
}

void init(){
    //
    srand(time(NULL));

    //show mob x, y
    showMob1_x = 70;
    showMob1_y = 75;
    showMob2_x = 290;
    showMob2_y = 75;

    //player 1, 2
    p[1].money = 0;
    p[1].blood = 1000;
    p[1].count = 0;
    p[1].border = showMob1_x;

    p[2].money = 0;
    p[2].blood = 1000;
    p[2].count = 0;
    p[2].border = showMob2_x;

    //4:snow
    monster_attr[4].img_l = read_image("images\\monsters\\snow_l.pixel", "images\\monsters\\snow_l.color");
    monster_attr[4].img_r = read_image("images\\monsters\\snow_r.pixel", "images\\monsters\\snow_r.color");
    monster_attr[4].cost = 12;
    monster_attr[4].w = 42;
    monster_attr[4].h = 27;
    monster_attr[4].blood = 500;
    monster_attr[4].attack = 35;
    monster_attr[4].defense = 3;
    monster_attr[4].move_speed = 6;
    monster_attr[4].atk_speed = 33;
    monster_attr[4].money = 6;

    //3:pig
    monster_attr[3].img_l = read_image("images\\monsters\\pig_l.pixel", "images\\monsters\\pig_l.color");
    monster_attr[3].img_r = read_image("images\\monsters\\pig_r.pixel", "images\\monsters\\pig_r.color");
    monster_attr[3].cost = 12;
    monster_attr[3].w = 28;
    monster_attr[3].h = 12;
    monster_attr[3].blood = 500;
    monster_attr[3].attack = 35;
    monster_attr[3].defense = 3;
    monster_attr[3].move_speed = 4;
    monster_attr[3].atk_speed = 33;
    monster_attr[3].money = 6;

    //2:muhroom
    monster_attr[2].img_l = read_image("images\\monsters\\muhroom_l.pixel", "images\\monsters\\muhroom_l.color");
    monster_attr[2].img_r = read_image("images\\monsters\\muhroom_r.pixel", "images\\monsters\\muhroom_r.color");
    monster_attr[2].cost = 12;
    monster_attr[2].w = 28;
    monster_attr[2].h = 15;
    monster_attr[2].blood = 500;
    monster_attr[2].attack = 35;
    monster_attr[2].defense = 3;
    monster_attr[2].move_speed = 5;
    monster_attr[2].atk_speed = 33;
    monster_attr[2].money = 6;

    //1:green
    monster_attr[1].img_l = read_image("images\\monsters\\green_l.pixel", "images\\monsters\\green_l.color");
    monster_attr[1].img_r = read_image("images\\monsters\\green_r.pixel", "images\\monsters\\green_r.color");
    monster_attr[1].cost = 12;
    monster_attr[1].w = 28;
    monster_attr[1].h = 12;
    monster_attr[1].blood = 777;
    monster_attr[1].attack = 77;
    monster_attr[1].defense = 3;
    monster_attr[1].move_speed = 3;
    monster_attr[1].atk_speed = 28;
    monster_attr[1].money = 6;

    //0:snail
    monster_attr[0].img_l = read_image("images\\monsters\\snail_l.pixel", "images\\monsters\\snail_l.color");
    monster_attr[0].img_r = read_image("images\\monsters\\snail_r.pixel", "images\\monsters\\snail_r.color");
    monster_attr[0].cost = 12;
    monster_attr[0].w = 15;
    monster_attr[0].h = 9;
    monster_attr[0].blood = 500;
    monster_attr[0].attack = 35;
    monster_attr[0].defense = 3;
    monster_attr[0].move_speed = 5;
    monster_attr[0].atk_speed = 33;
    monster_attr[0].money = 6;
}

void init_mob(Mob *monster, int player, int type){
    monster->cost = monster_attr[type].cost;
    monster->w = monster_attr[type].w;
    monster->h = monster_attr[type].h;
    monster->blood = monster_attr[type].blood;
    monster->attack = monster_attr[type].attack;
    monster->defense = monster_attr[type].defense;
    monster->move_speed = monster_attr[type].move_speed;
    monster->atk_speed = monster_attr[type].atk_speed + offset(2);
    monster->money = monster_attr[type].money;
    if (player==1){
        monster->img = monster_attr[type].img_l;
        monster->move_unit = 1;
        monster->x = showMob1_x;
        monster->y = showMob1_y - monster->h;
    }else if (player==2){
        monster->img = monster_attr[type].img_r;
        monster->move_unit = -1;
        monster->x = showMob2_x - monster->w;
        monster->y = showMob2_y - monster->h;
    }
    monster->floor = monster->y;
    monster->move_flag = 0;
    monster->atk_flag = 0;
    monster->ver_flag = 0;
    monster->hor_flag = 0;
    monster->hp = monster->blood;
    monster->harm = 0;
    monster->state = 1;
}

Mob *playerMob(int player, int n){
    return &p[player].monster[(n+p[player].front+MOB_MAX_COUNT)%MOB_MAX_COUNT];
}

int mobState(int player, int n){
    return playerMob(player, n)->state;
}

void addMob(int player, int type){
    if (p[player].count < MOB_MAX_COUNT){
        if(p[player].count == 0) p[player].front = 0;
        Mob *monster = playerMob(player, p[player].count);
        init_mob(monster, player, type);

        p[player].count++;

        //adjust player's border
        if(p[1].count == 1){
            p[1].border = monster->x + monster->w;
        }else if(p[2].count == 1){
            p[2].border = monster->x;
        }
    }
}

void updateMobBorder(int player, Mob *monster){
    if(player == 1){
        p[1].border = monster->x + monster->w;
    }else if (player == 2){
        p[2].border = monster->x;
    }
}

void moveMob(int player, int n){
    Mob *monster = playerMob(player, n);
    int move = 0;
    if(monster->move_flag == 0){
        if(n == 0){                           //first monster
            updateMobBorder(player, monster);
            if(p[1].border >= p[2].border){   //left >= right
                monster->wall = monster->x;
                monster->state = 2;
                move = 0;
            }else{
                move = 1;
            }
        }else{                                //not first monster
            Mob *last_monster = playerMob(player, n-1);
            if((player == 1 && (monster->x + monster->w) >= (last_monster->x)) ||
               (player == 2 && (monster->x) <= (last_monster->x + last_monster->w))){
                move = 0;
            }else{
                move = 1;
            }
        }
    }else{
        move = 0;
    }

    if(move){
        show_image(monster->img, monster->x+=monster->move_unit, monster->floor);
    }else{
        show_image(monster->img, monster->x, monster->floor);
    }

    monster->move_flag = (monster->move_flag + 1) % monster->move_speed;
}

//2
void attackMob(int player){
    Mob *monster = playerMob(player, 0);
    Mob *enemy = playerMob(3-player, 0);

    if(p[3-player].count)
        showHarm(playerMob(3-player, 0));

    if(p[1].border < p[2].border)
        monster->state = 1;

    if(monster->atk_flag == 0){
        monster->harm = 0;
        if(player == 1){
            monster->state = 3;
        }else if(player == 2){
            monster->state = 4;
        }
    }
    monster->x = monster->wall;
    monster->y = monster->floor;
    show_image(monster->img, monster->wall, monster->floor);
    monster->atk_flag = (monster->atk_flag + 1) % monster->atk_speed;
}

void moveMobLeft(int player, int n){
    Mob *monster = playerMob(player, 0);
    Mob *enemy = playerMob(3-player, 0);

    show_image(monster->img, monster->x-=monster->hor_flag, monster->floor);
    monster->hor_flag+=1;
    if(monster->hor_flag >= 4){
        monster->hor_flag = 0;

        if(player == 1){
            monster->state = 4;
        }else if(player == 2){
            monster->state = 2;

            if(p[3-player].count != 0){
                //harm and lost blood
                enemy->harm = randHarm(monster->attack) - enemy->defense;
                enemy->hp = enemy->hp - enemy->harm;
                if(enemy->hp <= 0){
                    enemy->state = 7;
                }else{
                    enemy->state = 5;
                }
            }else{                      //hit the castle
                p[3-player].blood -= randHarm(monster->attack) - enemy->defense;
            }
        }
    }
}

void moveMobRight(int player, int n){
    Mob *monster = playerMob(player, 0);
    Mob *enemy = playerMob(3-player, 0);

    show_image(monster->img, monster->x+=monster->hor_flag, monster->floor);
    monster->hor_flag+=1;
    if(monster->hor_flag >= 4){
        monster->hor_flag = 0;
        if(player == 1){
            monster->state = 2;

            if(p[3-player].count != 0){
                //harm and lost blood
                enemy->harm = randHarm(monster->attack) - enemy->defense;
                enemy->hp = enemy->hp - enemy->harm;
                if(enemy->hp <= 0){
                    enemy->state = 7;
                }else{
                    enemy->state = 5;
                }
            }else{                           //hit the castle
                p[3-player].blood -= randHarm(monster->attack) - enemy->defense;
            }
        }else if(player == 2){
            monster->state = 3;
        }
    }
}

void showHarm(Mob *monster){
    if (monster->harm)
        putStringLarge(large_font, monster->x + (monster->w-15)/2, monster->y - 15, int2string(monster->harm), 15);
}

void moveMobUp(int player, int n){
    Mob *monster = playerMob(player, 0);
    Mob *enemy = playerMob(3-player, 0);

    show_image(monster->img, monster->x, monster->y-=(monster->ver_flag));
    monster->ver_flag+=1;
    if(monster->ver_flag >= 5){
        monster->ver_flag = 0;
        if(player == 1){
            monster->state = 6;
        }else if(player == 2){
            monster->state = 2;
        }
    }

    showHarm(monster);
}

void moveMobDown(int player, int n){
    Mob *monster = playerMob(player, 0); //&p[player].monster[p[player].front];
    Mob *enemy = playerMob(3-player, 0); //&p[3-player].monster[p[3-player].front];

    show_image(monster->img, monster->x, monster->y+=(monster->ver_flag)%4);
    monster->ver_flag+=1;
    if(monster->ver_flag >= 8){
        monster->ver_flag = 0;
        if(player == 1){
            monster->state = 2;
        }else if(player == 2){
            monster->state = 5;
        }
    }

    showHarm(monster);
}

void dieMob(int player){
    //destroy_image(&p[player].monster[p[player].front].img);
    p[player].count--;
    if(p[player].count >= 1){
        Mob *monster = &p[player].monster[(p[player].front+1) % MOB_MAX_COUNT];
        p[player].front++;
        updateMobBorder(player, monster);
    }else if(p[player].count == 0){
        if(player == 1){
            p[1].border = showMob1_x;
        }else if(player == 2){
            p[2].border = showMob2_x;
        }
    }
}

void test(char *c, int n){
    putStringLarge(large_font, 0, n*6, c, 15);
}

int main(){
    large_font = read_font("font.txt");

    init();
    addMob(1, 0);
    addMob(1, 1);
    addMob(1, 2);
    addMob(1, 3);
    addMob(1, 4);
    addMob(2, 4);
    addMob(2, 3);
    addMob(2, 2);
    addMob(2, 1);
    addMob(2, 0);

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
