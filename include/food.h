#ifndef HW1_FOOD_H
#define HW1_FOOD_H
#include <bits/types/FILE.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct foodname {
    char* name;
    size_t size;
} foodname;


typedef struct food {
    foodname name;
    double protein;  // белки
    double fats;    // жиры
    double carb;    // углеводы
    double energy;  // энергетическая ценность
} food;

typedef struct filter_fields{
    double max_carb;
    double min_protein;
}filter_fields;


typedef struct composite_ration {
    food* array;
    size_t len_array;
} composite_ration;


composite_ration init_ration(FILE* fp);
void select_breakfast(composite_ration, filter_fields);

#endif //HW1_FOOD_H
