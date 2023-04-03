#pragma once

#include <SFML/Graphics.hpp>
#define YAML_CPP_DLL
#include <yaml-cpp/yaml.h>
#include <functional>
#include <vector>
#include <string>
#include <thread>

#include "constants.h"
#include "sorting_function.h"

class SortingAlgo {
public:
	SortingAlgo(const std::string name, const SortingFunction sorting_function, int num_elems, int update_delay)
		: name(name), sorting_function(sorting_function), num_elements(num_elems), update_delay(update_delay) {}

	void run(sf::RenderWindow& window, const sf::Font& font) const;

private:
	std::string name;
	SortingFunction sorting_function;
	int num_elements;
	int update_delay;
};

std::vector<SortingAlgo> createSortingAlgos(YAML::Node yaml_data);