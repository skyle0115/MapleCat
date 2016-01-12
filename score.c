#include "score.h"

int is_ranking_file_exist(){
    FILE *fp = fopen("ranking.txt","r");
    if(fp == NULL){
        return 0;
    }else{
        fclose(fp);
        return 1;
    }
}

void init_ranking(){
    int i;
    FILE *fp = fopen("ranking.txt","w");
    for(i = 0; i < RANKING_SIZE; i++)
        fprintf(fp,"0\n");
    fclose(fp);
}

int *ranking_array(){
    int i,
        *arr = malloc(RANKING_SIZE * sizeof(int));
    FILE *fp = fopen("ranking.txt","r");
    for(i = 0; i < RANKING_SIZE; i++)
        fscanf(fp, "%d", &arr[i]);
    fclose(fp);
    return arr;
}

void update_ranking(int score){
    int i, j,
        *arr = ranking_array();
    for(i = 0; i < RANKING_SIZE; i++)
        if(arr[i] < score){
            for(j = RANKING_SIZE - 1; j > i; j--)
                arr[j] = arr[j-1];
            arr[i] = score;
            break;
        }

    FILE *fp = fopen("ranking.txt","w");
    for(i = 0; i < RANKING_SIZE; i++)
        fprintf(fp,"%d\n", arr[i]);
    fclose(fp);
}

void print_ranking(){
    int i,
        *arr = ranking_array();
    for(i = 0; i < RANKING_SIZE; i++)
        printf("%d ", arr[i]);
}



