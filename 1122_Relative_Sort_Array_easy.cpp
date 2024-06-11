class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() == 1)
            return arr1;
        
        int len_1 = arr1.size();
        int len_2 = arr2.size();
        int idx [1001];
        fill(idx, idx+1001, len_2);

        for (int i = 0; i < len_2; i++)
            idx[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&](int a, int b){
            if (idx[a] == idx[b])
                return a < b;
            return idx[a] < idx[b];
        });

        return arr1;
    }
};