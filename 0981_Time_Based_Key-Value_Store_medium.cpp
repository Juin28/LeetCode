class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& searched = mp[key];
        int l = 0;
        int r = searched.size() - 1;
        string result = "";

        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (searched[m].first <= timestamp)
            {
                result = searched[m].second;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return result;
    }
};
