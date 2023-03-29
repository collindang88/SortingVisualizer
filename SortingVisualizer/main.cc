#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

#include "sorting_algos.h"
#include "constants.h"

import bubble_sort;
import heap_sort;
import insertion_sort;
import selection_sort;
import utils;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, DISABLE_RESIZE);
	window.setFramerateLimit(FRAME_RATE_LIMIT);

	sf::Font font;
	if (!font.loadFromFile(FONT_FILE_PATH))
	{
		std::cerr << FONT_LOAD_FAILED;
		return EXIT_FAILURE;
	}

	std::vector<std::pair<std::string, SortingAlgorithm>> sorting_algos{
		{HEAP_SORT, heapSort},
		{BUBBLE_SORT, bubbleSort},
		{INSERTION_SORT, insertionSort},
		{SELECTION_SORT, selectionSort},
	};

	while (1) {
		for (const auto& sorting_algo_pair : sorting_algos) {
			auto nums = generateRandomNumbers(NUM_ELEMENTS, WINDOW_HEIGHT);
			const auto& [sorting_algo_name, sorting_algo] = sorting_algo_pair;
			const auto sortingAlgoText = createSortingAlgoText(font, sorting_algo_name);

			auto updateWindow = [&]() {
				const auto bars = createBars(nums);
				drawAndUpdateWindow(window, bars, sortingAlgoText);
			};

			sorting_algo(nums, updateWindow);
		}
	}

	return EXIT_SUCCESS;
}