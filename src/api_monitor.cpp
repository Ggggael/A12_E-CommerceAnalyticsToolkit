//src/api_monitor.cpp

#include "api_monitor.hpp"

std::pair<std::vector<std::string>, int> find_most_frequent_endpoints(const std::vector<std::string>& log_data){
    std::unordered_map<std::string, int> api_call_count;
    std::vector<std::string> result;
    int max_freq = 0;
    for(size_t i=0; i<log_data.size(); i++){
        if(api_call_count.find(log_data[i]) != api_call_count.end()){
            int frequency = api_call_count.at(log_data[i]);
            frequency++;
            api_call_count[log_data[i]] = frequency;
            if(frequency>max_freq){
                max_freq = frequency;
            }
        }
        else{
            api_call_count.insert({log_data[i], 1});
        }
    }
    for(auto it = api_call_count.begin(); it != api_call_count.end(); it++){
        if(it->second==max_freq){
            result.push_back(it->first);
        }
    }

    std::sort(result.begin(), result.end());

    return {result, max_freq};

}