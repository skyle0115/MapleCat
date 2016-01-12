#ifndef SCORE
#define SCORE
#include <stdio.h>
#define RANKING_SIZE 8

int is_ranking_file_exist();
void init_ranking();
int *ranking_array();
void update_ranking(int score);
void print_ranking();

#endif
