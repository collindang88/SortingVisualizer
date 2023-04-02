#include "pch.h"

import quick_sort;

TEST(QuickSortTests, SortPositiveNumbers) {
    std::vector<int> input{ 5, 1, 9, 3, 2 };
    std::vector<int> expected{ 1, 2, 3, 5, 9 };
    quickSort(input);
    ASSERT_EQ(input, expected);
}

TEST(QuickSortTests, SortNegativeNumbers) {
    std::vector<int> input{ -3, -2, -10, -1, -8 };
    std::vector<int> expected{ -10, -8, -3, -2, -1 };
    quickSort(input);
    ASSERT_EQ(input, expected);
}

TEST(QuickSortTests, SortMixedNumbers) {
    std::vector<int> input{ -3, -2, -10, 1, 8 };
    std::vector<int> expected{ -10, -3, -2, 1, 8 };
    quickSort(input);
    ASSERT_EQ(input, expected);
}

TEST(QuickSortTests, SortDuplicateNumbers) {
    std::vector<int> input{ 7, 7, 8, 9, 8, 9, 10 };
    std::vector<int> expected{ 7, 7, 8, 8, 9, 9, 10 };
    quickSort(input);
    ASSERT_EQ(input, expected);
}

TEST(QuickSortTests, EmptyArray) {
    std::vector<int> input{};
    std::vector<int> expected{};
    quickSort(input);
    ASSERT_EQ(input, expected);
}

TEST(QuickSortTests, SingleElementArray) {
    std::vector<int> input{ 7 };
    std::vector<int> expected{ 7 };
    quickSort(input);
    ASSERT_EQ(input, expected);
}
