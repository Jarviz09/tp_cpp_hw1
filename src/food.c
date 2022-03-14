#include "../include/food.h"
#include "../include/utils.h"
#include "string.h"

#define MAX_NAME_SIZE 50

composite_ration init_ration(FILE* fp) {
    composite_ration Object;
    Object.len_array = 1; // текущая длина массива
    size_t i = 0;

    Object.array = (food*)calloc(Object.len_array, sizeof(food));
    char name[MAX_NAME_SIZE];

    while(1) {
        char *isNameReadOk = fgets(name, MAX_NAME_SIZE, fp);
        int isRationReadOk = fscanf(
                fp,
                "%lf\t%lf\t%lf\t%lf\n",
                &Object.array[i].protein,
                &Object.array[i].fats,
                &Object.array[i].carb,
                &Object.array[i].energy) == 4;

        if (isNameReadOk == NULL || !isRationReadOk) return Object;

        Object.array[i].name.size = strlen(name) + 1;

        Object.array[i].name.name = (char*)calloc(Object.array[i].name.size, sizeof(char));
        if (Object.array[i].name.name == NULL) {
            return Object;
        }

        strncpy(Object.array[i].name.name, name, Object.array[i].name.size - 2);
        Object.array[i].name.name[Object.array[i].name.size - 1] = '\0';

        if (Object.len_array == i + 1) { // если память закончилась
            Object = increase_memory(Object); // расширяем массив в 2 раза
        }

        ++i;
    }
}


void select_breakfast(composite_ration Object, filter_fields Filters) {
    int is_first_entry = 0;
    int is_exist_filtered = 0;

    for (size_t i = 0; i < Object.len_array; ++i) {
        if (is_selected(Object, Filters.min_protein, Filters.max_carb, i)) {
            print_breakfast(Object, i, is_first_entry);
            is_first_entry = 1;
            is_exist_filtered = 1;
        }
    }

    if (!is_exist_filtered) {
        not_found();
    }

}
