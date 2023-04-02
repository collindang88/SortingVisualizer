#include <SFML/Graphics.hpp>
#define YAML_CPP_DLL
#include <yaml-cpp/yaml.h>
#include <vector>
#include <string>
#include <functional>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>

#include "constants.h"
#include "sorting_function.h"
#include "sorting_algo.h"

export module utils;

export std::vector<int> generateRandomNumbers(int num_elements, int max_number) {
	std::vector<int> nums(num_elements);
	for (int i = 0; i < num_elements; i++) {
		nums[i] = std::rand() % max_number;
	}
	return nums;
}

export void handleEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

export sf::Text createSortingAlgoText(const sf::Font& font, const std::string& sorting_algo_name) {
	sf::Text sortingAlgoText;
	sortingAlgoText.setFont(font);
	sortingAlgoText.setCharacterSize(FONT_CHAR_SIZE);
	sortingAlgoText.setFillColor(FONT_COLOR);
	sortingAlgoText.setPosition(FONT_X_POS, FONT_X_POS);
	sortingAlgoText.setString(sorting_algo_name);
	return sortingAlgoText;
}

export std::vector<sf::RectangleShape> createBars(const std::vector<int>& nums) {
	std::vector<sf::RectangleShape> bars(nums.size());
	const float bar_width = static_cast<float>(WINDOW_WIDTH) / nums.size();
	for (int i = 0; i < nums.size(); i++) {
		bars[i] = sf::RectangleShape(sf::Vector2f(bar_width, static_cast<float>(nums[i])));
		bars[i].setPosition(sf::Vector2f(static_cast<float>(i * bar_width), static_cast<float>(WINDOW_HEIGHT - nums[i])));
		bars[i].setFillColor(BAR_FILL_COLOR);
		bars[i].setOutlineThickness(BAR_OUTLINE_THICKNESS);
		bars[i].setOutlineColor(BAR_OUTLINE_COLOR);
	}
	return bars;
}

export void drawAndUpdateWindow(sf::RenderWindow& window, const std::vector<sf::RectangleShape>& bars, const sf::Text& sortingAlgoText) {
	window.clear(BACKGROUND_COLOR);
	for (auto& bar : bars) {
		window.draw(bar);
	}

	window.draw(sortingAlgoText);

	handleEvents(window);
	window.display();
}

export YAML::Node loadYamlFile(const std::string& path) {
	std::ifstream yaml_file(path);
	return YAML::Load(yaml_file);
}

export sf::Font loadFont() {
	sf::Font font;
	if (!font.loadFromFile(FONT_FILE_PATH)) {
		std::cerr << FONT_LOAD_FAILED;
		exit(EXIT_FAILURE);
	}
	return font;
}
