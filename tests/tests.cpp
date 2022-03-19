#include <gtest/gtest.h>

#include <exception>
#include <stdexcept>

extern "C" {
#include "include/food.h"
#include "include/utils.h"
}

TEST(TestOpenedFile, isOpened) {
  const char* file1 = "tests/testfiles/ration.txt";
  const char* file2 = "asd";
  FILE* fp1 = open_file(file1);
  FILE* fp2 = open_file(file2);

  EXPECT_NE(nullptr, fp1);
  EXPECT_EQ(nullptr, fp2);

  if (fp1 != nullptr) {
    fclose(fp1);
  }

  if (fp2 != nullptr) {
    fclose(fp2);
  }
}

TEST(TestReadData, isRead) {
  FILE* fp = open_file("tests/testfiles/init_data.txt");
  filter_fields expected;
  filter_fields got;
  expected.min_protein = 5;
  expected.max_carb = 50;
  got = read_filters(fp);
  EXPECT_EQ(expected.min_protein, got.min_protein);
  EXPECT_EQ(expected.max_carb, got.max_carb);
  fclose(fp);
}

TEST(TestInitRation, isInit) {
  composite_ration Object;
  composite_ration Object2;
  Object2.len_array = 4;
  Object2.array = alloc_memory_for_array(Object2);
  ASSERT_NE(nullptr, Object2.array);

  Object2.array[0].name.size = 8;
  Object2.array[1].name.size = 10;
  Object2.array[2].name.size = 28;

  Object2.array[0].protein = 50.3;
  Object2.array[0].fats = 34.2;
  Object2.array[0].carb = 17.2;
  Object2.array[0].energy = 108.3;

  Object2.array[1].protein = 12.4;
  Object2.array[1].fats = 20.2;
  Object2.array[1].carb = 70.2;
  Object2.array[1].energy = 60.3;

  Object2.array[2].protein = 7.3;
  Object2.array[2].fats = 15.2;
  Object2.array[2].carb = 32.2;
  Object2.array[2].energy = 30.6;

  for (size_t i = 0; i < Object2.len_array; ++i) {
    Object2.array[i].name.name = alloc_memory_for_name(Object2, i);
  }

  strncpy(Object2.array[0].name.name, "Omelet", Object2.array[0].name.size);
  strncpy(Object2.array[1].name.name, "Porridge", Object2.array[1].name.size);
  strncpy(Object2.array[2].name.name, "Coffee with milk and cream",
          Object2.array[2].name.size);

  FILE* fp = open_file("tests/testfiles/ration.txt");
  Object = init_ration(fp);

  ASSERT_EQ(Object.len_array, Object2.len_array);

  for (size_t i = 0; i < Object2.len_array - 1; ++i) {
    EXPECT_TRUE(!strncmp(Object.array[i].name.name, Object2.array[i].name.name,
                         Object2.array[i].name.size));
    EXPECT_EQ(Object.array[i].name.size, Object2.array[i].name.size);
    EXPECT_EQ(Object.array[i].protein, Object2.array[i].protein);
    EXPECT_EQ(Object.array[i].fats, Object2.array[i].fats);
    EXPECT_EQ(Object.array[i].carb, Object2.array[i].carb);
    EXPECT_EQ(Object.array[i].energy, Object2.array[i].energy);
  }
  free_ration(Object);
  free_ration(Object2);
  fclose(fp);
}

TEST(TestAllocArray, isAlloced) {
  composite_ration Object;
  Object.len_array = 3;
  Object.array = alloc_memory_for_array(Object);
  ASSERT_NE(nullptr, Object.array);
  free(Object.array);
}

TEST(TestAllocName, isAllocedName) {
  composite_ration Object;
  Object.len_array = 1;
  Object.array = alloc_memory_for_array(Object);
  Object.array[0].name.name = alloc_memory_for_name(Object, 0);
  ASSERT_NE(nullptr, Object.array[0].name.name);
  free_ration(Object);
}

TEST(TestSelectBreakfast, isSelected) {
  FILE* fp = open_file("tests/testfiles/ration.txt");
  composite_ration Object;
  Object = init_ration(fp);

  filter_fields Filter;
  Filter.max_carb = 50;
  Filter.min_protein = 5;

  selected_array expected_dish;
  expected_dish.size = 0;
  if ((expected_dish.names = (char**)calloc(Object.len_array, sizeof(char*))) !=
      NULL) {
    if ((expected_dish.names[0] =
             (char*)calloc(Object.array[0].name.size, sizeof(char))) != NULL) {
      expected_dish.size = 1;
      if ((expected_dish.names[1] = (char*)calloc(Object.array[2].name.size,
                                                  sizeof(char))) != NULL) {
        expected_dish.size = 2;

        strncpy(expected_dish.names[0], "Omelet", Object.array[0].name.size);
        strncpy(expected_dish.names[1], "Coffee with milk and cream",
                Object.array[2].name.size);

        selected_array dish = select_breakfast(Object, Filter);

        EXPECT_TRUE(!strncmp(expected_dish.names[0], dish.names[0],
                             Object.array[0].name.size));
        EXPECT_TRUE(!strncmp(expected_dish.names[1], dish.names[1],
                             Object.array[2].name.size));
        print_breakfast(dish);
        free_selected(dish);
      }
    }
  }
  free_selected(expected_dish);
  free_ration(Object);
  fclose(fp);
}

TEST(TestIncreaseMemory, isIncreased) {
  FILE* fp = open_file("tests/testfiles/ration.txt");
  composite_ration Object;
  composite_ration Object2;
  Object = init_ration(fp);
  fclose(fp);

  fp = open_file("tests/testfiles/ration.txt");

  Object2 = init_ration(fp);

  Object = increase_memory(Object);

  EXPECT_EQ(Object.len_array, 2 * Object2.len_array);

  for (size_t i = 0; i < Object2.len_array - 1; ++i) {
    EXPECT_TRUE(!strncmp(Object.array[i].name.name, Object2.array[i].name.name,
                         Object2.array[i].name.size));
    EXPECT_EQ(Object.array[i].name.size, Object2.array[i].name.size);
    EXPECT_EQ(Object.array[i].protein, Object2.array[i].protein);
    EXPECT_EQ(Object.array[i].fats, Object2.array[i].fats);
    EXPECT_EQ(Object.array[i].carb, Object2.array[i].carb);
    EXPECT_EQ(Object.array[i].energy, Object2.array[i].energy);
  }

  free_ration(Object2);
  free_ration(Object);
  fclose(fp);
}

TEST(TestSelected, isSelected) {
  composite_ration Object;
  double min_protein = 5.0;
  double max_carb = 50.0;
  FILE* fp = open_file("tests/testfiles/ration.txt");
  Object = init_ration(fp);
  EXPECT_TRUE(is_selected(Object, min_protein, max_carb, 0));
  EXPECT_FALSE(is_selected(Object, min_protein, max_carb, 1));

  free_ration(Object);
  fclose(fp);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
