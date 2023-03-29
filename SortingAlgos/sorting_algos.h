#pragma once
#include <functional>
#include <vector>

using SortingAlgorithm = std::function<void(std::vector<int>&, std::function<void()>)>;
