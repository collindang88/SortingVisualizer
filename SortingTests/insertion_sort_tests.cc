#include "pch.h"

import insertion_sort;

TEST(InsertionSortTests, SortPositiveNumbers) {
    std::vector<int> input{ 5, 1, 9, 3, 2 };
    std::vector<int> expected{ 1, 2, 3, 5, 9 };
    insertionSort(input);
    ASSERT_EQ(input, expected);
}

TEST(InsertionSortTests, SortNegativeNumbers) {
    std::vector<int> input{ -3, -2, -10, -1, -8 };
    std::vector<int> expected{ -10, -8, -3, -2, -1 };
    insertionSort(input);
    ASSERT_EQ(input, expected);
}

TEST(InsertionSortTests, SortMixedNumbers) {
    std::vector<int> input{ -3, -2, -10, 1, 8 };
    std::vector<int> expected{ -10, -3, -2, 1, 8 };
    insertionSort(input);
    ASSERT_EQ(input, expected);
}

TEST(InsertionSortTests, EmptyArray) {
    std::vector<int> input{};
    std::vector<int> expected{};
    insertionSort(input);
    ASSERT_EQ(input, expected);
}

TEST(InsertionSortTests, SingleElementArray) {
    std::vector<int> input{ 7 };
    std::vector<int> expected{ 7 };
    insertionSort(input);
    ASSERT_EQ(input, expected);
}