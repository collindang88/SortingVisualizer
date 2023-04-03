#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

import dummy_callback;

export module heap_sort;

void heapify(std::vector<int>& nums, int n, int i, std::function<void()> updateWindow = dummyCallback) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
        largest = left;

    if (right < n && nums[right] > nums[largest])
        largest = right;

    if (largest != i) {
        std::swap(nums[i], nums[largest]);
        updateWindow();
        heapify(nums, n, largest, updateWindow);
    }
}

export void heapSort(std::vector<int>& arr, std::function<void()> updateWindow = dummyCallback) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, updateWindow);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, updateWindow);
    }
}