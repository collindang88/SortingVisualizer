#include <vector>
#include <functional>

import dummy_callback;

export module quick_sort;

int partition(std::vector<int>& nums, int lo, int hi, std::function<void()> updateWindow = dummyCallback) {
    int pivot = nums[hi];
    int left = lo;
    int right = hi - 1;

    while (left <= right) {
        while (left <= right && nums[left] <= pivot) {
            left++;
        }
        while (left <= right && nums[right] >= pivot) {
            right--;
        }
        if (left < right) {
            std::swap(nums[left], nums[right]);
            updateWindow();
        }
    }
    std::swap(nums[left], nums[hi]);
    updateWindow();
    return left;
}

void quickSort(std::vector<int>& nums, int lo, int hi, std::function<void()> updateWindow = dummyCallback) {
	if (lo < hi) {
		int pivot_index = partition(nums, lo, hi, updateWindow);
		quickSort(nums, lo, pivot_index - 1, updateWindow);
		quickSort(nums, pivot_index + 1, hi, updateWindow);
	}
}

export void quickSort(std::vector<int>& nums, std::function<void()> updateWindow = dummyCallback) {
	quickSort(nums, 0, nums.size() - 1, updateWindow);
}