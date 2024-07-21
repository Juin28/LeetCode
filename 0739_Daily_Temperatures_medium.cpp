// Optimized solution using stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result (n, 0);
        stack<int> small;
        stack<int> index;
        small.push(temperatures[0]);
        index.push(0);

        for(int i = 1; i < n; ++i)
        {
            int num = temperatures[i];
            while (!small.empty() && num > small.top())
            {
                int idx = index.top();
                result[idx] = i - idx;;
                small.pop();
                index.pop();
            }
            small.push(num);
            index.push(i);
        }

        return result;
    }
};



// Brute-Froce
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         int highest_idx = n - 1;
//         int highest_temp = temperatures[highest_idx];
//         vector<int> result (n, 0);

//         for (int i = n-2; i >= 0; --i)
//         {
//             if (temperatures[i] >= highest_temp)
//             {
//                 highest_idx = i;
//                 highest_temp = temperatures[i];
//             }
//             else
//             {
//                 int j = i + 1;
//                 while (j <= highest_idx)
//                 {
//                     if (temperatures[j] > temperatures[i])
//                     {
//                         result[i] = j - i;
//                         break;
//                     }
//                     ++j;
//                 }
//             }
//         }

//         return result;
//     }
// };
