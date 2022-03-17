#include <stdio.h>
#include "include/food.h"
#include "include/utils.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Введите имя файла единственным аргументом\n");
        return INCORRECT_COUNT_FILE;
    }

    FILE* fp = open_file(argv[1]);

    if (fp == NULL) {
        printf("Не удалось открыть файл\n");
        return NOT_OPENED_FILE;
    }


    composite_ration comp_ration = init_ration(fp);

    filter_fields Filters = read_filters(stdin);

    if (Filters.min_protein == 0 || Filters.max_carb == 0) {
        printf("Введите корректно критерии поиска завтрака\n");
        return INCORRECT_FILTERS;

    }

    selected_array filtered_names = select_breakfast(comp_ration, Filters);
    print_breakfast(filtered_names);
    free_ration(comp_ration);
    free_selected(filtered_names);


    fclose(fp);

    return SUCCESS;
}
