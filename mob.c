#include "mob.h"
#include "hit.h"

Font *large_font;
Mob monster_attr[100];
Player p[3];
//
Image *green_l[7];
Image *green_r[6];
int green_dir; //0 = r, 1 = l
int green_x, green_y,
    greem_height, green_width,
    green_flag;

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
    monster_attr[4].img_hit_l = read_image("images\\mob\\snow\\hit1_0_l.pixel", "images\\mob\\snow\\hit1_0_l.color");
    monster_attr[4].img_hit_r = read_image("images\\mob\\snow\\hit1_0_r.pixel", "images\\mob\\snow\\hit1_0_r.color");
    monster_attr[4].img_move_l[0] = read_image("images\\mob\\snow\\move_0_l.pixel", "images\\mob\\snow\\move_0_l.color");
    monster_attr[4].img_move_r[0] = read_image("images\\mob\\snow\\move_0_r.pixel", "images\\mob\\snow\\move_0_r.color");
    monster_attr[4].img_move_l[1] = read_image("images\\mob\\snow\\move_1_l.pixel", "images\\mob\\snow\\move_1_l.color");
    monster_attr[4].img_move_r[1] = read_image("images\\mob\\snow\\move_1_r.pixel", "images\\mob\\snow\\move_1_r.color");
    monster_attr[4].img_move_l[2] = read_image("images\\mob\\snow\\move_2_l.pixel", "images\\mob\\snow\\move_2_l.color");
    monster_attr[4].img_move_r[2] = read_image("images\\mob\\snow\\move_2_r.pixel", "images\\mob\\snow\\move_2_r.color");
    monster_attr[4].img_move_l[3] = read_image("images\\mob\\snow\\move_3_l.pixel", "images\\mob\\snow\\move_3_l.color");
    monster_attr[4].img_move_r[3] = read_image("images\\mob\\snow\\move_3_r.pixel", "images\\mob\\snow\\move_3_r.color");
    monster_attr[4].img_stand_l[0] = read_image("images\\mob\\snow\\stand_0_l.pixel", "images\\mob\\snow\\stand_0_l.color");
    monster_attr[4].img_stand_r[0] = read_image("images\\mob\\snow\\stand_0_r.pixel", "images\\mob\\snow\\stand_0_r.color");
    monster_attr[4].img_stand_l[1] = read_image("images\\mob\\snow\\stand_1_l.pixel", "images\\mob\\snow\\stand_1_l.color");
    monster_attr[4].img_stand_r[1] = read_image("images\\mob\\snow\\stand_1_r.pixel", "images\\mob\\snow\\stand_1_r.color");
    monster_attr[4].img_stand_l[2] = read_image("images\\mob\\snow\\stand_2_l.pixel", "images\\mob\\snow\\stand_2_l.color");
    monster_attr[4].img_stand_r[2] = read_image("images\\mob\\snow\\stand_2_r.pixel", "images\\mob\\snow\\stand_2_r.color");
    monster_attr[4].img_stand_l[3] = read_image("images\\mob\\snow\\stand_3_l.pixel", "images\\mob\\snow\\stand_3_l.color");
    monster_attr[4].img_stand_r[3] = read_image("images\\mob\\snow\\stand_3_r.pixel", "images\\mob\\snow\\stand_3_r.color");
    monster_attr[4].img_stand_l[4] = read_image("images\\mob\\snow\\stand_4_l.pixel", "images\\mob\\snow\\stand_4_l.color");
    monster_attr[4].img_stand_r[4] = read_image("images\\mob\\snow\\stand_4_r.pixel", "images\\mob\\snow\\stand_4_r.color");
    monster_attr[4].img_stand_l[5] = read_image("images\\mob\\snow\\stand_5_l.pixel", "images\\mob\\snow\\stand_5_l.color");
    monster_attr[4].img_stand_r[5] = read_image("images\\mob\\snow\\stand_5_r.pixel", "images\\mob\\snow\\stand_5_r.color");
    monster_attr[4].img_stand_l[6] = read_image("images\\mob\\snow\\stand_6_l.pixel", "images\\mob\\snow\\stand_6_l.color");
    monster_attr[4].img_stand_r[6] = read_image("images\\mob\\snow\\stand_6_r.pixel", "images\\mob\\snow\\stand_6_r.color");
    monster_attr[4].img_stand_l[7] = read_image("images\\mob\\snow\\stand_7_l.pixel", "images\\mob\\snow\\stand_7_l.color");
    monster_attr[4].img_stand_r[7] = read_image("images\\mob\\snow\\stand_7_r.pixel", "images\\mob\\snow\\stand_7_r.color");
    monster_attr[4].img_stand_l[8] = read_image("images\\mob\\snow\\stand_8_l.pixel", "images\\mob\\snow\\stand_8_l.color");
    monster_attr[4].img_stand_r[8] = read_image("images\\mob\\snow\\stand_8_r.pixel", "images\\mob\\snow\\stand_8_r.color");
    monster_attr[4].stand_img_count = 9;
    monster_attr[4].move_img_count = 4;
    monster_attr[4].stand_img_speed = 25;
    monster_attr[4].move_img_speed = 25;
    monster_attr[4].cost = 12;
    monster_attr[4].w = 60;
    monster_attr[4].h = 31;
    monster_attr[4].blood = 500;
    monster_attr[4].attack = 35;
    monster_attr[4].defense = 3;
    monster_attr[4].move_speed = 2;
    monster_attr[4].atk_speed = 33;
    monster_attr[4].money = 6;

    //3:mushroom
    monster_attr[3].img_hit_l = read_image("images\\mob\\spirit\\hit1_0_l.pixel", "images\\mob\\spirit\\hit1_0_l.color");
    monster_attr[3].img_hit_r = read_image("images\\mob\\spirit\\hit1_0_r.pixel", "images\\mob\\spirit\\hit1_0_r.color");
    monster_attr[3].img_move_l[0] = read_image("images\\mob\\spirit\\move_0_l.pixel", "images\\mob\\spirit\\move_0_l.color");
    monster_attr[3].img_move_r[0] = read_image("images\\mob\\spirit\\move_0_r.pixel", "images\\mob\\spirit\\move_0_r.color");
    monster_attr[3].img_move_l[1] = read_image("images\\mob\\spirit\\move_1_l.pixel", "images\\mob\\spirit\\move_1_l.color");
    monster_attr[3].img_move_r[1] = read_image("images\\mob\\spirit\\move_1_r.pixel", "images\\mob\\spirit\\move_1_r.color");
    monster_attr[3].img_move_l[2] = read_image("images\\mob\\spirit\\move_2_l.pixel", "images\\mob\\spirit\\move_2_l.color");
    monster_attr[3].img_move_r[2] = read_image("images\\mob\\spirit\\move_2_r.pixel", "images\\mob\\spirit\\move_2_r.color");
    monster_attr[3].img_move_l[3] = read_image("images\\mob\\spirit\\move_3_l.pixel", "images\\mob\\spirit\\move_3_l.color");
    monster_attr[3].img_move_r[3] = read_image("images\\mob\\spirit\\move_3_r.pixel", "images\\mob\\spirit\\move_3_r.color");
    monster_attr[3].img_stand_l[0] = read_image("images\\mob\\spirit\\stand_0_l.pixel", "images\\mob\\spirit\\stand_0_l.color");
    monster_attr[3].img_stand_r[0] = read_image("images\\mob\\spirit\\stand_0_r.pixel", "images\\mob\\spirit\\stand_0_r.color");
    monster_attr[3].img_stand_l[1] = read_image("images\\mob\\spirit\\stand_1_l.pixel", "images\\mob\\spirit\\stand_1_l.color");
    monster_attr[3].img_stand_r[1] = read_image("images\\mob\\spirit\\stand_1_r.pixel", "images\\mob\\spirit\\stand_1_r.color");
    monster_attr[3].img_stand_l[2] = read_image("images\\mob\\spirit\\stand_2_l.pixel", "images\\mob\\spirit\\stand_2_l.color");
    monster_attr[3].img_stand_r[2] = read_image("images\\mob\\spirit\\stand_2_r.pixel", "images\\mob\\spirit\\stand_2_r.color");
    monster_attr[3].img_stand_l[3] = read_image("images\\mob\\spirit\\stand_3_l.pixel", "images\\mob\\spirit\\stand_3_l.color");
    monster_attr[3].img_stand_r[3] = read_image("images\\mob\\spirit\\stand_3_r.pixel", "images\\mob\\spirit\\stand_3_r.color");
    monster_attr[3].img_stand_l[4] = read_image("images\\mob\\spirit\\stand_4_l.pixel", "images\\mob\\spirit\\stand_4_l.color");
    monster_attr[3].img_stand_r[4] = read_image("images\\mob\\spirit\\stand_4_r.pixel", "images\\mob\\spirit\\stand_4_r.color");
    monster_attr[3].img_stand_l[5] = read_image("images\\mob\\spirit\\stand_5_l.pixel", "images\\mob\\spirit\\stand_5_l.color");
    monster_attr[3].img_stand_r[5] = read_image("images\\mob\\spirit\\stand_5_r.pixel", "images\\mob\\spirit\\stand_5_r.color");
    monster_attr[3].img_stand_l[6] = read_image("images\\mob\\spirit\\stand_6_l.pixel", "images\\mob\\spirit\\stand_6_l.color");
    monster_attr[3].img_stand_r[6] = read_image("images\\mob\\spirit\\stand_6_r.pixel", "images\\mob\\spirit\\stand_6_r.color");
    monster_attr[3].stand_img_count = 7;
    monster_attr[3].move_img_count = 4;
    monster_attr[3].stand_img_speed = 25;
    monster_attr[3].move_img_speed = 25;
    monster_attr[3].cost = 12;
    monster_attr[3].w = 25;
    monster_attr[3].h = 16;
    monster_attr[3].blood = 500;
    monster_attr[3].attack = 35;
    monster_attr[3].defense = 3;
    monster_attr[3].move_speed = 3;
    monster_attr[3].atk_speed = 33;
    monster_attr[3].money = 6;

    //2:muhroom
    monster_attr[2].img_hit_l = read_image("images\\mob\\mushroom\\hit1_0_l.pixel", "images\\mob\\mushroom\\hit1_0_l.color");
    monster_attr[2].img_hit_r = read_image("images\\mob\\mushroom\\hit1_0_r.pixel", "images\\mob\\mushroom\\hit1_0_r.color");
    monster_attr[2].img_move_l[0] = read_image("images\\mob\\mushroom\\move_0_l.pixel", "images\\mob\\mushroom\\move_0_l.color");
    monster_attr[2].img_move_r[0] = read_image("images\\mob\\mushroom\\move_0_r.pixel", "images\\mob\\mushroom\\move_0_r.color");
    monster_attr[2].img_move_l[1] = read_image("images\\mob\\mushroom\\move_1_l.pixel", "images\\mob\\mushroom\\move_1_l.color");
    monster_attr[2].img_move_r[1] = read_image("images\\mob\\mushroom\\move_1_r.pixel", "images\\mob\\mushroom\\move_1_r.color");
    monster_attr[2].img_move_l[2] = read_image("images\\mob\\mushroom\\move_2_l.pixel", "images\\mob\\mushroom\\move_2_l.color");
    monster_attr[2].img_move_r[2] = read_image("images\\mob\\mushroom\\move_2_r.pixel", "images\\mob\\mushroom\\move_2_r.color");
    monster_attr[2].img_move_l[3] = read_image("images\\mob\\mushroom\\move_3_l.pixel", "images\\mob\\mushroom\\move_3_l.color");
    monster_attr[2].img_move_r[3] = read_image("images\\mob\\mushroom\\move_3_r.pixel", "images\\mob\\mushroom\\move_3_r.color");
    monster_attr[2].img_stand_l[0] = read_image("images\\mob\\mushroom\\stand_0_l.pixel", "images\\mob\\mushroom\\stand_0_l.color");
    monster_attr[2].img_stand_r[0] = read_image("images\\mob\\mushroom\\stand_0_r.pixel", "images\\mob\\mushroom\\stand_0_r.color");
    monster_attr[2].img_stand_l[1] = read_image("images\\mob\\mushroom\\stand_1_l.pixel", "images\\mob\\mushroom\\stand_1_l.color");
    monster_attr[2].img_stand_r[1] = read_image("images\\mob\\mushroom\\stand_1_r.pixel", "images\\mob\\mushroom\\stand_1_r.color");
    monster_attr[2].stand_img_count = 2;
    monster_attr[2].move_img_count = 4;
    monster_attr[2].stand_img_speed = 20;
    monster_attr[2].move_img_speed = 20;
    monster_attr[2].cost = 12;
    monster_attr[2].w = 30;
    monster_attr[2].h = 15;
    monster_attr[2].blood = 500;
    monster_attr[2].attack = 35;
    monster_attr[2].defense = 3;
    monster_attr[2].move_speed = 6;
    monster_attr[2].atk_speed = 33;
    monster_attr[2].money = 6;

    //1:pig
    monster_attr[1].img_hit_l = read_image("images\\mob\\pig\\hit1_0_l.pixel", "images\\mob\\pig\\hit1_0_l.color");
    monster_attr[1].img_hit_r = read_image("images\\mob\\pig\\hit1_0_r.pixel", "images\\mob\\pig\\hit1_0_r.color");
    monster_attr[1].img_move_l[0] = read_image("images\\mob\\pig\\move_0_l.pixel", "images\\mob\\pig\\move_0_l.color");
    monster_attr[1].img_move_r[0] = read_image("images\\mob\\pig\\move_0_r.pixel", "images\\mob\\pig\\move_0_r.color");
    monster_attr[1].img_move_l[1] = read_image("images\\mob\\pig\\move_1_l.pixel", "images\\mob\\pig\\move_1_l.color");
    monster_attr[1].img_move_r[1] = read_image("images\\mob\\pig\\move_1_r.pixel", "images\\mob\\pig\\move_1_r.color");
    monster_attr[1].img_move_l[2] = read_image("images\\mob\\pig\\move_2_l.pixel", "images\\mob\\pig\\move_2_l.color");
    monster_attr[1].img_move_r[2] = read_image("images\\mob\\pig\\move_2_r.pixel", "images\\mob\\pig\\move_2_r.color");
    monster_attr[1].img_stand_l[0] = read_image("images\\mob\\pig\\stand_0_l.pixel", "images\\mob\\pig\\stand_0_l.color");
    monster_attr[1].img_stand_r[0] = read_image("images\\mob\\pig\\stand_0_r.pixel", "images\\mob\\pig\\stand_0_r.color");
    monster_attr[1].img_stand_l[1] = read_image("images\\mob\\pig\\stand_1_l.pixel", "images\\mob\\pig\\stand_1_l.color");
    monster_attr[1].img_stand_r[1] = read_image("images\\mob\\pig\\stand_1_r.pixel", "images\\mob\\pig\\stand_1_r.color");
    monster_attr[1].img_stand_l[2] = read_image("images\\mob\\pig\\stand_2_l.pixel", "images\\mob\\pig\\stand_2_l.color");
    monster_attr[1].img_stand_r[2] = read_image("images\\mob\\pig\\stand_2_r.pixel", "images\\mob\\pig\\stand_2_r.color");
    monster_attr[1].stand_img_count = 3;
    monster_attr[1].move_img_count = 3;
    monster_attr[1].stand_img_speed = 15;
    monster_attr[1].move_img_speed = 15;
    monster_attr[1].cost = 12;
    monster_attr[1].w = 35;
    monster_attr[1].h = 15;
    monster_attr[1].blood = 777;
    monster_attr[1].attack = 77;
    monster_attr[1].defense = 3;
    monster_attr[1].move_speed = 5;
    monster_attr[1].atk_speed = 28;
    monster_attr[1].money = 6;

    //0:snail
    monster_attr[0].img_hit_l = read_image("images\\mob\\snail\\hit1_0_l.pixel", "images\\mob\\snail\\hit1_0_l.color"),
    monster_attr[0].img_hit_r = read_image("images\\mob\\snail\\hit1_0_r.pixel", "images\\mob\\snail\\hit1_0_r.color"),
    monster_attr[0].img_move_l[0] = read_image("images\\mob\\snail\\move_0_l.pixel", "images\\mob\\snail\\move_0_l.color");
    monster_attr[0].img_move_r[0] = read_image("images\\mob\\snail\\move_0_r.pixel", "images\\mob\\snail\\move_0_r.color");
    monster_attr[0].img_move_l[1] = read_image("images\\mob\\snail\\move_1_l.pixel", "images\\mob\\snail\\move_1_l.color");
    monster_attr[0].img_move_r[1] = read_image("images\\mob\\snail\\move_1_r.pixel", "images\\mob\\snail\\move_1_r.color");
    monster_attr[0].img_move_l[2] = read_image("images\\mob\\snail\\move_2_l.pixel", "images\\mob\\snail\\move_2_l.color");
    monster_attr[0].img_move_r[2] = read_image("images\\mob\\snail\\move_2_r.pixel", "images\\mob\\snail\\move_2_r.color");
    monster_attr[0].img_move_l[3] = read_image("images\\mob\\snail\\move_3_l.pixel", "images\\mob\\snail\\move_3_l.color");
    monster_attr[0].img_move_r[3] = read_image("images\\mob\\snail\\move_3_r.pixel", "images\\mob\\snail\\move_3_r.color");
    monster_attr[0].img_stand_l[0] = read_image("images\\mob\\snail\\stand_0_l.pixel", "images\\mob\\snail\\stand_0_l.color");
    monster_attr[0].img_stand_r[0] = read_image("images\\mob\\snail\\stand_0_r.pixel", "images\\mob\\snail\\stand_0_r.color");
    monster_attr[0].stand_img_count = 1;
    monster_attr[0].move_img_count = 4;
    monster_attr[0].stand_img_speed = 30;
    monster_attr[0].move_img_speed = 30;
    monster_attr[0].cost = 12;
    monster_attr[0].w = 25;
    monster_attr[0].h = 14;
    monster_attr[0].blood = 500;
    monster_attr[0].attack = 35;
    monster_attr[0].defense = 3;
    monster_attr[0].move_speed = 7;
    monster_attr[0].atk_speed = 33;
    monster_attr[0].money = 6;

    //green
    int green_lIdx;
    for(green_lIdx = 0; green_lIdx < 7; green_lIdx++){
        char pixName[256], colorName[256];
        snprintf(pixName, sizeof pixName, "%s%01d%s", "images\\mob\\green\\green_l_", green_lIdx, ".pixel");
        snprintf(colorName, sizeof colorName, "%s%01d%s", "images\\mob\\green\\green_l_", green_lIdx, ".color");
        green_l[green_lIdx] = read_image(pixName, colorName);
    }

    int green_rIdx;
    for(green_rIdx = 0; green_rIdx < 6; green_rIdx++){
        char pixName[256], colorName[256];
        snprintf(pixName, sizeof pixName, "%s%01d%s", "images\\mob\\green\\green_r_", green_rIdx, ".pixel");
        snprintf(colorName, sizeof colorName, "%s%01d%s", "images\\mob\\green\\green_r_", green_rIdx, ".color");
        green_r[green_rIdx] = read_image(pixName, colorName);
    }

    green_dir = 0;
    greem_height = 28;
    green_width = 36;
    green_x = 0;
    green_y = 100 - greem_height;
    green_flag = 0;
}

void init_mob(Mob *monster, int player, int type){
    monster->stand_img_count = monster_attr[type].stand_img_count;
    monster->move_img_count = monster_attr[type].move_img_count;
    monster->stand_img_speed = monster_attr[type].stand_img_speed;
    monster->move_img_speed = monster_attr[type].move_img_speed;
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
        memcpy(monster->img_stand, monster_attr[type].img_stand_l, sizeof(monster_attr[type].img_stand_l));
        memcpy(monster->img_move, monster_attr[type].img_move_l, sizeof(monster_attr[type].img_move_l));
        monster->img_hit = monster_attr[type].img_hit_l;
        monster->move_unit = 1;
        monster->x = showMob1_x;
        monster->y = showMob1_y - monster->h;
    }else if (player==2){
        memcpy(monster->img_stand, monster_attr[type].img_stand_r, sizeof(monster_attr[type].img_stand_r));
        memcpy(monster->img_move, monster_attr[type].img_move_r, sizeof(monster_attr[type].img_move_r));
        monster->img_hit = monster_attr[type].img_hit_r;
        monster->move_unit = -1;
        monster->x = showMob2_x - monster->w;
        monster->y = showMob2_y - monster->h;
    }
    monster->floor = monster->y;
    monster->move_flag = 0;
    monster->atk_flag = 0;
    monster->ver_flag = 0;
    monster->hor_flag = 0;
    monster->stand_img_index = 0;
    monster->move_img_index = 0;
    monster->stand_img_flag = 0;
    monster->move_img_flag = 0;
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
        if(p[player].money >= monster_attr[type].cost){
            p[player].money -= monster_attr[type].cost;
        }else{
            return;
        }
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

void movingMobImg(Mob *monster, int x, int y){
    show_image(monster->img_move[monster->move_img_index], x, y);
    if(monster->move_img_flag == 0){
        monster->move_img_index = (monster->move_img_index + 1) % monster->move_img_count;
    }
    monster->move_img_flag = (monster->move_img_flag + 1) % monster->move_img_speed;
}

void attackingMobImg(Mob *monster, int x, int y){
    show_image(monster->img_stand[monster->stand_img_index], x, y);
    if(monster->stand_img_flag == 0){
        monster->stand_img_index = (monster->stand_img_index + 1) % monster->stand_img_count;
    }
    monster->stand_img_flag = (monster->stand_img_flag + 1) % monster->stand_img_speed;
}

void hitMobImg(Mob *monster, int x, int y){
    show_image(monster->img_hit, x, y);
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
        movingMobImg(monster, monster->x+=monster->move_unit, monster->floor);
    }else{
        movingMobImg(monster, monster->x, monster->floor);
    }

    monster->move_flag = (monster->move_flag + 1) % monster->move_speed;
}

//2
void attackMob(int player){
    Mob *monster = playerMob(player, 0);
    Mob *enemy = playerMob(3-player, 0);

    if(p[3-player].count)
        showHarm(playerMob(3-player, 0));

    if(p[1].border < p[2].border){
        monster->state = 1;
        return;
    }

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
    attackingMobImg(monster, monster->wall, monster->floor);
    monster->atk_flag = (monster->atk_flag + 1) % monster->atk_speed;
}

void loseHp(Mob *monster, int value){
    Hitvoice();
    monster->harm = value; //randHarm(monster->attack) - enemy->defense;
    monster->hp = monster->hp - monster->harm;
}

void moveMobLeft(int player, int n){
    Mob *monster = playerMob(player, 0);
    Mob *enemy = playerMob(3-player, 0);

    attackingMobImg(monster, monster->x-=monster->hor_flag, monster->floor);
    monster->hor_flag+=1;
    if(monster->hor_flag >= 4){
        monster->hor_flag = 0;

        if(player == 1){
            monster->state = 4;
        }else if(player == 2){
            monster->state = 2;

            if(p[3-player].count != 0){
                loseHp(enemy, randHarm(monster->attack) - enemy->defense);
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

    attackingMobImg(monster, monster->x+=monster->hor_flag, monster->floor);
    monster->hor_flag+=1;
    if(monster->hor_flag >= 4){
        monster->hor_flag = 0;
        if(player == 1){
            monster->state = 2;

            if(p[3-player].count != 0){
                loseHp(enemy, randHarm(monster->attack) - enemy->defense);
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

    hitMobImg(monster, monster->x, monster->y-=(monster->ver_flag));
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

    hitMobImg(monster, monster->x, monster->y+=(monster->ver_flag)%4);
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
    Dievoice();
    p[player].count--;
    p[3 - player].money += playerMob(player, 0)->money;
    if(p[player].count >= 1){
        Mob *monster = playerMob(player, 1);
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

void green(){
    if(green_dir==0){
        green_x += 1;
        show_image(green_r[green_flag], green_x, green_y);
        if(green_x % 10 == 0)
            green_flag = (green_flag + 1)%6;
        if(green_x >= 360-green_width){
            green_dir = 1;
            green_flag = 0;
        }
    }else if(green_dir==1){
        green_x -= 1;
        show_image(green_l[green_flag], green_x, green_y);
        if(green_x % 10 == 0)
            green_flag = (green_flag + 1)%7;
        if(green_x <= 0){
            green_dir = 0;
            green_flag = 0;
        }
    }
}

void test(char *c, int n){
    putStringLarge(large_font, 0, n*6, c, 15);
}
