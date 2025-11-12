#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "box_optimizer.hpp"
#include "cart_analysis.hpp"
#include "customer_loyalty.hpp"
#include "api_monitor.hpp"

// Module 1: Box Fitting Optimizer
TEST_CASE("findItemsForBox finds two items that fit exactly") {
    std::vector<int> weights = {10, 20, 30, 40, 50};
    int box_capacity = 70;
    
    auto result = findItemsForBox(weights, box_capacity);
    
    REQUIRE(result.first == 2);
    REQUIRE(result.second == 3);
    REQUIRE(weights[result.first] + weights[result.second] == box_capacity);
}

// Module 2: Cart Analysis - Common Products
TEST_CASE("commonProductsAcrossCarts finds products in all carts") {
    std::vector<std::vector<std::string>> carts = {
        {"laptop", "mouse", "keyboard", "usb"},
        {"laptop", "mouse", "monitor"},
        {"mouse", "laptop", "webcam"}
    };
    
    auto result = commonProductsAcrossCarts(carts);
    
    REQUIRE(result.size() == 2);
    REQUIRE(result[0] == "laptop");
    REQUIRE(result[1] == "mouse");
}

// Module 3: Customer Loyalty Tiers
TEST_CASE("getLoyaltyTier returns correct tier based on score") {
    auto tiers = createLoyaltyTiers();
    
    REQUIRE(getLoyaltyTier(tiers, 0) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, 499) == "Bronze");
    REQUIRE(getLoyaltyTier(tiers, 500) == "Silver");
    REQUIRE(getLoyaltyTier(tiers, 1000) == "Gold");
    REQUIRE(getLoyaltyTier(tiers, 5000) == "Platinum");
}

// Module 4: API Endpoint Tracker
TEST_CASE("find_most_frequent_endpoints returns most called endpoints") {
    std::vector<std::string> logs = {
        "/api/cart", "/api/checkout", "/api/cart", 
        "/api/login", "/api/cart"
    };
    
    auto [endpoints, frequency] = find_most_frequent_endpoints(logs);
    
    REQUIRE(frequency == 3);
    REQUIRE(endpoints.size() == 1);
    REQUIRE(endpoints[0] == "/api/cart");
}