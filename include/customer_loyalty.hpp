// Customer Loyalty Header file
//include/customer_loyalty.hpp

#include <map>
#include <string>

std::map<int, std::string> createLoyaltyTiers();

std::string getLoyaltyTier(const std::map<int, std::string>& tiers, int score);
