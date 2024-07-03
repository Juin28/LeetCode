class Solution {
public:
    bool isHappy(int n) {
        unordered_map <int, bool> check;
        check[n] = false;
        
        while (n != 1 && !check[n])
        {
            check[n] = true;
            int sum = 0;
            int temp = n;
            while(temp)
            {
                sum += pow((temp%10), 2);
                temp /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
};