#include <vector>
#include <functional>

import dummy_callback;

export module insertion_sort;

export void insertionSort(std::vector<int>& nums, std::function<void()> updateWindow = dummyCallback) {
	for (int i = 1; i < nums.size(); i++) {
		int to_insert = nums[i];
		int j = i - 1;
		while (j >= 0 && to_insert < nums[j]) {
			nums[j + 1] = nums[j];
			updateWindow();
			j--;
		}
		nums[j + 1] = to_insert;
		updateWindow();
	}
}