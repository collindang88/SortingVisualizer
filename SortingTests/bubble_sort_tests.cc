#include "pch.h"

import bubble_sort;

TEST(BubbleSortTests, SortPositiveNumbers) {
    std::vector<int> input{ 5, 1, 9, 3, 2 };
    std::vector<int> expected{ 1, 2, 3, 5, 9 };
    bubbleSort(input);
    ASSERT_EQ(input, expected);
}

TEST(BubbleSortTests, SortNegativeNumbers) {
    std::vector<int> input{ -3, -2, -10, -1, -8 };
    std::vector<int> expected{ -10, -8, -3, -2, -1 };
    bubbleSort(input);
    ASSERT_EQ(input, expected);
}

TEST(BubbleSortTests, SortMixedNumbers) {
    std::vector<int> input{ -3, -2, -10, 1, 8 };
    std::vector<int> expected{ -10, -3, -2, 1, 8 };
    bubbleSort(input);
    ASSERT_EQ(input, expected);
}

TEST(BubbleSortTests, EmptyArray) {
    std::vector<int> input{};
    std::vector<int> expected{};
    bubbleSort(input);
    ASSERT_EQ(input, expected);
}

TEST(BubbleSortTests, SingleElementArray) {
    std::vector<int> input{ 7 };
    std::vector<int> expected{ 7 };
    bubbleSort(input);
    ASSERT_EQ(input, expected);
}