#include <vector>
#include <algorithm>
#include <utility>

export module heap_sort;

export void heap_sort(std::vector<int>& nums) {
	std::make_heap(nums.begin(), nums.end());
	
	for (int i = nums.size() - 1; i >= 0; i--) {
		std::swap(nums[0], nums[i]);
		std::make_heap(nums.begin(), nums.begin() + i);
	}
}