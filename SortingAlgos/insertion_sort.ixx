#include <vector>

export module insertion_sort;

export void insertion_sort(std::vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		int to_insert = nums[i];
		int j = i - 1;
		while (j >= 0 && to_insert < nums[j]) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = to_insert;
	}
}