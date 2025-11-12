#include "customer_loyalty.hpp"

std::map<int, std::string> createLoyaltyTiers(){
    std::map<int, std::string> map = {{0, "Bronze"}, {500, "Silver"}, {1000, "Gold"}, {2000, "Platinum"}};
    return map;
}

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score){
    auto it = tiers.lower_bound(score);
    if(it != tiers.end() && it->first == score){
        return it->second;
    }
    it--;
    return it->second;
}