#include <SFML/Graphics.hpp>
#include <yaml-cpp/yaml.h>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <fstream>

#include "sorting_algo.h"
#include "constants.h"

import utils;

int main()
{
	const auto yaml_data = loadYamlFile(SORTING_YAML);
	const auto font = loadFont();
	const auto sorting_algos = createSortingAlgos(yaml_data);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, DISABLE_RESIZE);
	window.setFramerateLimit(FRAME_RATE_LIMIT);

	while (1) {
		for (const auto& sorting_algo : sorting_algos) {
			sorting_algo.run(window, font);
		}
	}

	return EXIT_SUCCESS;
}