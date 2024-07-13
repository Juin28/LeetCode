class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector< vector <string> > group;
        unordered_map <string, vector<string>> connect;
        int cnt = 0;

        for(int i = 0; i < n; ++i)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            auto idx = connect.find(temp);
            if (idx != connect.end())
                connect[temp].push_back(strs[i]); 
            else
            {
                vector<string> temp_vec = {strs[i]};
                connect[temp] = temp_vec;
            }
        }
        
        for (auto i = connect.begin(); i != connect.end(); ++i)
        {
            group.push_back(i->second);
        }

        return group;
    }
};