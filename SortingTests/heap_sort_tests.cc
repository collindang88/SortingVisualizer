#include "pch.h"

import heap_sort;

TEST(HeapSortTests, SortPositiveNumbers) {
    std::vector<int> input{ 5, 1, 9, 3, 2 };
    std::vector<int> expected{ 1, 2, 3, 5, 9 };
    heap_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(HeapSortTests, SortNegativeNumbers) {
    std::vector<int> input{ -3, -2, -10, -1, -8 };
    std::vector<int> expected{ -10, -8, -3, -2, -1 };
    heap_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(HeapSortTests, SortMixedNumbers) {
    std::vector<int> input{ -3, -2, -10, 1, 8 };
    std::vector<int> expected{ -10, -3, -2, 1, 8 };
    heap_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(HeapSortTests, EmptyArray) {
    std::vector<int> input{};
    std::vector<int> expected{};
    heap_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(HeapSortTests, SingleElementArray) {
    std::vector<int> input{ 7 };
    std::vector<int> expected{ 7 };
    heap_sort(input);
    ASSERT_EQ(input, expected);
}