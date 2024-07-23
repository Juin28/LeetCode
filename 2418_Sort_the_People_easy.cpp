class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        people.reserve(heights.size());  // Pre-allocate memory

        for (size_t i = 0; i < heights.size(); ++i) 
        {
            people.emplace_back(heights[i], move(names[i]));
        }

        sort(people.begin(), people.end(), greater<>());

        vector<string> sortedPeople;
        sortedPeople.reserve(people.size());  // Pre-allocate memory

        for (auto& person : people) 
        {
            sortedPeople.push_back(move(person.second));
        }

        return sortedPeople;
    }
};