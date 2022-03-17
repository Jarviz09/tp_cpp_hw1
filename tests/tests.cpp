#include <exception>
#include <stdexcept>

#include <gtest/gtest.h>

extern "C" {
//#include "../include/utils.h"
#include "../include/food.h"
#include "../src/utils.c"
}

TEST(TestOpenedFile, isOpened) {
    const char* file1 = "../../ration.txt";
    const char* file2 = "asd";
    EXPECT_NE(nullptr, open_file(file1));
    EXPECT_EQ(nullptr, open_file(file2));
}


TEST(TestReadData, isRead) {
    FILE *fp = open_file("init_data.txt");
    filter_fields expected;
    filter_fields got;
    expected.min_protein = 5;
    expected.max_carb = 50;
    got = read_filters(fp);
    EXPECT_EQ(expected.min_protein, got.min_protein);
    EXPECT_EQ(expected.max_carb, got.max_carb);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}