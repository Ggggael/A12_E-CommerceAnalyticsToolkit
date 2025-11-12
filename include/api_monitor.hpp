// Api Endpoint Tracker header file 
//include/api_monitor.hpp

#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data);