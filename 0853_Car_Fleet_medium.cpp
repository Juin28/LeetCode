class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, pair<int, double>>> pos_speed_time (n, {0, {0, 0}});
        
        int cnt = 1;

        for (int i = 0; i < n; ++i)
        {
            int pos = position[i], spd = speed[i];
            pos_speed_time[i].first = pos;
            pos_speed_time[i].second.first = spd;
            pos_speed_time[i].second.second = static_cast<double>(target - pos) / static_cast<double>(spd);
        }

        sort(pos_speed_time.begin(), pos_speed_time.end());

        double prev = pos_speed_time[n-1].second.second;
        for (int i = n - 2; i >= 0; --i)
        {
            if (pos_speed_time[i].second.second <= prev)
                continue;
                
            prev = pos_speed_time[i].second.second;
            cnt++;
        }

        return cnt;
    }
};
