
#ifndef HW1_UTILS_H
#define HW1_UTILS_H
#include "food.h"

typedef enum {
    SUCCESS = 0,
    INCORRECT_COUNT_FILE,
    NOT_OPENED_FILE,
    INCORRECT_FILTERS
} errors_name;

FILE* open_file(const char*);
filter_fields read_filters(FILE* fp);
composite_ration increase_memory(composite_ration); //
food* alloc_memory_for_array(composite_ration);
char* alloc_memory_for_name(composite_ration, size_t);
int is_selected(composite_ration, double, double, size_t); //
void print_breakfast(selected_array);
void free_ration(composite_ration);
void free_selected(selected_array);

#endif //HW1_UTILS_H
