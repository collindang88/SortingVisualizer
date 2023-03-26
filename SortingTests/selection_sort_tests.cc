#include "pch.h"

import selection_sort;

TEST(SelectionSortTests, SortPositiveNumbers) {
    std::vector<int> input{ 5, 1, 9, 3, 2 };
    std::vector<int> expected{ 1, 2, 3, 5, 9 };
    selection_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(SelectionSortTests, SortNegativeNumbers) {
    std::vector<int> input{ -3, -2, -10, -1, -8 };
    std::vector<int> expected{ -10, -8, -3, -2, -1 };
    selection_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(SelectionSortTests, SortMixedNumbers) {
    std::vector<int> input{ -3, -2, -10, 1, 8 };
    std::vector<int> expected{ -10, -3, -2, 1, 8 };
    selection_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(SelectionSortTests, EmptyArray) {
    std::vector<int> input{};
    std::vector<int> expected{};
    selection_sort(input);
    ASSERT_EQ(input, expected);
}

TEST(SelectionSortTests, SingleElementArray) {
    std::vector<int> input{ 7 };
    std::vector<int> expected{ 7 };
    selection_sort(input);
    ASSERT_EQ(input, expected);
}