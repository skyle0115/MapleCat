#ifndef MOB
#define MOB

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

char* int2string(int value);
int float2int(float f);
int randHarm(int harm);
int offset(int v);
void init();
void init_mob(Mob *monster, int player, int type);
Mob *playerMob(int player, int n);
int mobState(int player, int n);
void addMob(int player, int type);
void updateMobBorder(int player, Mob *monster);
void moveMob(int player, int n);
void attackMob(int player);
void moveMobLeft(int player, int n);
void moveMobRight(int player, int n);
void showHarm(Mob *monster);
void moveMobUp(int player, int n);
void moveMobDown(int player, int n);
void dieMob(int player);
void test(char *c, int n);

#endif
