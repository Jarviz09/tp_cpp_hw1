#include <stdio.h>
#include "../include/utils.h"

FILE* open_file(const char* file) {
    FILE* fp;
    fp = fopen(file, "r");
    return fp;
}

composite_ration increase_memory(composite_ration Object) {
    size_t new_current_len = Object.len_array * 2;
    food* new_ration = (food*) calloc(new_current_len,sizeof(food));
    for (size_t i = 0; i < Object.len_array; ++i) {
        new_ration[i] = Object.array[i];
    }

    free(Object.array);

    Object.array = new_ration;
    Object.len_array = new_current_len;
    return Object;
}

void print_breakfast(selected_array dish) {

    for (size_t i = 0; i < dish.size; ++i) {
        printf("%s\n", dish.names[i]);
    }

    if (dish.size == 0) {
        printf("Завтрака по вашим критериям не найдено\n");
    }
}


void free_ration(composite_ration comp_ration) {
    for (size_t i = 0; i < comp_ration.len_array; ++i) {
        free(comp_ration.array[i].name.name);
    }
    free(comp_ration.array);
}


int is_selected(composite_ration Object, double min_protein, double max_carb, size_t index) {
    if (Object.array[index].protein >= min_protein && Object.array[index].carb <= max_carb) {
        return 1;
    }
    return 0;
}


filter_fields read_filters(FILE* fp) {

    double min_protein;
    double max_carb;
    filter_fields Filters;
    Filters.max_carb = 0;
    Filters.min_protein = 0;

    printf("Введите минимально желаемое количество белков в блюде\n");


    if (fscanf(fp,"%lf", &min_protein) != 1) {
        return Filters;
    }

    printf("Введите максимальное количество углеводов в блюде\n");


    if (fscanf(fp,"%lf", &max_carb) != 1) {
        return Filters;
    }

    Filters.max_carb = max_carb;
    Filters.min_protein = min_protein;

    return Filters;

}

food* alloc_memory_for_array(composite_ration Object) {
    Object.array = (food*)calloc(Object.len_array, sizeof(food));
    return Object.array;
}


char* alloc_memory_for_name(composite_ration Object, size_t index) {
    Object.array[index].name.name = (char*)calloc(Object.array[index].name.size, sizeof(char));
    return Object.array[index].name.name;
}


void free_selected(selected_array dish) {
    for (size_t i = 0; i < dish.size; ++i) {
        free(dish.names[i]);
    }
    free(dish.names);
}
