#include <SFML/Graphics.hpp>
#include <yaml-cpp/yaml.h>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <fstream>

#include "sorting_algos.h"
#include "constants.h"

import bubble_sort;
import heap_sort;
import insertion_sort;
import selection_sort;
import quick_sort;
import utils;

int main()
{
	std::ifstream yaml_file(SORTING_YAML);
	YAML::Node yaml_data = YAML::Load(yaml_file);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, DISABLE_RESIZE);
	window.setFramerateLimit(FRAME_RATE_LIMIT);

	sf::Font font;
	if (!font.loadFromFile(FONT_FILE_PATH))
	{
		std::cerr << FONT_LOAD_FAILED;
		return EXIT_FAILURE;
	}

	std::vector<std::pair<std::string, SortingAlgorithm>> sorting_algos{
		{QUICK_SORT, [](std::vector<int>& nums, std::function<void()> updateWindow) {
			quickSort(nums, updateWindow);
			}},
		{HEAP_SORT, heapSort},
		{BUBBLE_SORT, bubbleSort},
		{INSERTION_SORT, insertionSort},
		{SELECTION_SORT, selectionSort},
	};

	while (1) {
		for (const auto& sorting_algo_pair : sorting_algos) {
			const auto& [sorting_algo_name, sorting_algo] = sorting_algo_pair;
			auto num_elements = yaml_data[sorting_algo_name][NUM_ELEMENTS].as<int>();
			auto update_delay = yaml_data[sorting_algo_name][UPDATE_DELAY].as<int>();
			auto nums = generateRandomNumbers(num_elements, WINDOW_HEIGHT);
			const auto sortingAlgoText = createSortingAlgoText(font, sorting_algo_name);

			auto updateWindow = [&]() {
				const auto bars = createBars(nums);
				drawAndUpdateWindow(window, bars, sortingAlgoText);
				std::this_thread::sleep_for(std::chrono::milliseconds(update_delay));
			};

			sorting_algo(nums, updateWindow);
		}
	}

	return EXIT_SUCCESS;
}