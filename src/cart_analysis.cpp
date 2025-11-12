//src/cart_analysis.cpp

#include "cart_analysis.hpp"

std::vector<std::string> commonProductsAcrossCarts(const std::vector<std::vector<std::string>>& carts){
    std::unordered_map<std::string, int> map;
    std::vector<std::string> common;
    for(size_t i=0; i<carts.size(); i++){
        for(size_t j=0; j< carts[i].size(); j++){
            if(map.find(carts[i][j]) != map.end()){
                int product_count = map.at(carts[i][j]);
                product_count++;
                map[carts[i][j]]= product_count;
            }
            else{
                map.insert({carts[i][j], 1});
            }
        }
    }

    for(auto it = map.begin(); it != map.end(); it++){
        if(it->second==carts.size()){
            common.push_back(it->first);
        }
    }

    std::sort(common.begin(), common.end());
    return common;
}