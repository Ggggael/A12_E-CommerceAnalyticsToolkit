//src/box_optimizer.cpp

#include "box_optimizer.hpp"

std::pair<int, int> findItemsForBox(const std::vector<int>& item_weights, int box_capacity){
    std::unordered_map<int, int> map={};
    for(size_t i=0; i<item_weights.size(); i++){
        int num = item_weights[i];
        int remaining = box_capacity - num;
        if(map.find(remaining) != map.end()){       //Doesn't allow map.contains
            int found = map[remaining];
            return {found, i};
        }
        map.insert({num, i});
    }

    return {-1, -1};
}
