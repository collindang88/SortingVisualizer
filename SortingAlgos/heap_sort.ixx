#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

import dummy_callback;

export module heap_sort;

export void heapSort(std::vector<int>& nums, std::function<void()> updateWindow = dummyCallback) {
	std::make_heap(nums.begin(), nums.end());
	
	for (int i = nums.size() - 1; i >= 0; i--) {
		std::swap(nums[0], nums[i]);
		updateWindow();
		std::make_heap(nums.begin(), nums.begin() + i);
		updateWindow();
	}
}