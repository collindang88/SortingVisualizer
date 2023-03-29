#include <vector>
#include <functional>

import dummy_callback;

export module selection_sort;

export void selectionSort(std::vector<int>& nums, std::function<void()> updateWindow = dummyCallback) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[i]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				updateWindow();
			}
		}
	}
}