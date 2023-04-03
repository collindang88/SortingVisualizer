#include <functional>
#include <vector>
#include <string>
#include <thread>

#include "constants.h"
#include "sorting_function.h"
#include "sorting_algo.h"

import bubble_sort;
import heap_sort;
import insertion_sort;
import selection_sort;
import quick_sort;

import utils;

void SortingAlgo::run(sf::RenderWindow& window, const sf::Font& font) const {
	auto nums = generateRandomNumbers(num_elements, WINDOW_HEIGHT);
	const auto sortingAlgoText = createSortingAlgoText(font, name);

	auto updateWindow = [&]() {
		const auto bars = createBars(nums);
		drawAndUpdateWindow(window, bars, sortingAlgoText);
		std::this_thread::sleep_for(std::chrono::milliseconds(update_delay));
	};

	sorting_function(nums, updateWindow);
}

std::vector<SortingAlgo> createSortingAlgos(YAML::Node yaml_data) {
	std::vector<std::pair<std::string, SortingFunction>> pairs{
		{HEAP_SORT, heapSort},
		{QUICK_SORT, [](std::vector<int>& nums, std::function<void()> updateWindow) {
			quickSort(nums, updateWindow);
			}},
		{BUBBLE_SORT, bubbleSort},
		{INSERTION_SORT, insertionSort},
		{SELECTION_SORT, selectionSort},
	};

	std::vector<SortingAlgo> sorting_algos;
	for (const auto& [sorting_algo_name, sorting_function] : pairs) {
		auto num_elements = yaml_data[sorting_algo_name][NUM_ELEMENTS].as<int>();
		auto update_delay = yaml_data[sorting_algo_name][UPDATE_DELAY].as<int>();
		sorting_algos.emplace_back(sorting_algo_name, sorting_function, num_elements, update_delay);
	}
	return sorting_algos;
}