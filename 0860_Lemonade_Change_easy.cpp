class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changes [3] = {0, 0, 0};
        int notes [2] = {5, 10};
        for (int b : bills) 
        {
            if (b == 5)
                changes[0]++;
            else 
            {
                int change = b - 5;
                for(int i = 1; i >= 0; --i)
                {
                    while(changes[i] && change - notes[i] >= 0)
                    {
                        change -= notes[i];
                        changes[i]--;
                    }
                }

                if (change != 0)
                    return false;
                
                if (b == 10)
                    changes[1]++;
                else
                    changes[2]++;
            }
        }
        return true;
    }
};