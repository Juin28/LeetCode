class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount (26, 0);

        for (char task : tasks) {
            taskCount[task - 'A']++;
        }

        vector<int> sortedTaskCount (taskCount.begin(), taskCount.end());
        sort(sortedTaskCount.begin(), sortedTaskCount.end());
        
        int maxCount = sortedTaskCount.back();
        int idleTime = (maxCount - 1) * n;
        sortedTaskCount.pop_back();

        while(sortedTaskCount.size() && idleTime > 0) {
            idleTime -= min(maxCount - 1, sortedTaskCount.back());
            sortedTaskCount.pop_back();
        }

        idleTime = max(0, idleTime);

        return tasks.size() + idleTime;
    }
};

