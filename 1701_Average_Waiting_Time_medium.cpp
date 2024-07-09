class Solution {
public:
    double averageWaitingTime(const vector<vector<int>>& customers) {
        double total_time = 0;
        int chef_avail = customers[0][0];
        double n = customers.size();

        for (const vector<int>& c : customers)
        {
            if ( chef_avail > c[0] )
            {
                total_time += chef_avail - c[0] + c[1];
                chef_avail += c[1];
            }
            else
            {
                total_time += c[1];
                chef_avail = c[0] + c[1];
            }
        }

        return total_time / n;
    }
};