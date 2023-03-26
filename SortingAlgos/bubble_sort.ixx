#include <vector>

export module bubble_sort;

export void bubble_sort(std::vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size() - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}