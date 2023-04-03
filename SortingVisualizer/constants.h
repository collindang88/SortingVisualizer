#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// Window settings
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Sorting Visualization";
const sf::Uint32 DISABLE_RESIZE = sf::Style::Titlebar | sf::Style::Close;

// Sorting settings
const std::string SORTING_YAML = "sorting_settings.yml";
const std::string NUM_ELEMENTS = "num_elements";
const std::string UPDATE_DELAY = "update_delay";


// Visual settings
const sf::Color BAR_FILL_COLOR = sf::Color::White;
const sf::Color BAR_OUTLINE_COLOR = sf::Color::Black;
const float BAR_OUTLINE_THICKNESS = -1.0f;
const sf::Color BACKGROUND_COLOR = sf::Color::Black;

// Time settings
const int FRAME_RATE_LIMIT = 60;
const int UPDATE_WINDOW_DELAY_MS = 100;

// Sorting types
const std::string HEAP_SORT = "Heap Sort";
const std::string SELECTION_SORT = "Selection Sort";
const std::string INSERTION_SORT = "Insertion Sort";
const std::string BUBBLE_SORT = "Bubble Sort";
const std::string QUICK_SORT = "Quick Sort";

// Font settings
const std::string FONT_LOAD_FAILED = "Error: Failed to load font.\n";
const std::string FONT_FILE_PATH = "oddly_calming_font.ttf";
const sf::Color FONT_COLOR = sf::Color::White;
const int FONT_CHAR_SIZE = 30;
const int FONT_X_POS = 10;
const int FONT_Y_POS = 10;