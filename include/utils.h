
#ifndef HW1_UTILS_H
#define HW1_UTILS_H
#include "food.h"

typedef enum {
    SUCCESS = 0,
    INCORRECT_COUNT_FILE,
    NOT_OPENED_FILE,
    INCORRECT_FILTERS
} errors_name;

FILE* open_file(char*);
filter_fields read_filters();
void not_found();
composite_ration increase_memory(composite_ration);
int is_selected(composite_ration, double, double, size_t);
void print_breakfast(composite_ration, size_t, int);
void free_ration(composite_ration);

#endif //HW1_UTILS_H
