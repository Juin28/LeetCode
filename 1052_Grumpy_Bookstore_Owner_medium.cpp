class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total = 0;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                total += customers[i];

            else if (i < minutes)
                sum += customers[i];
        }

        int maxS = sum;

        for (int i = minutes; i < n; i++) {
            if (grumpy[i - minutes])
                sum -= customers[i - minutes];

            if (grumpy[i])
                sum += customers[i];

            maxS = max(maxS, sum);
        }

        return total + maxS;
    }
};