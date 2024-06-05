class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int head = 0;
        int tail = 0;
        while (num[tail] != '\0')
        {
            tail++;
        }
        tail--;
        while (head < tail)
        {
            // cout << "head = " << head << "tail = " << tail << endl;
            if (num[head] != num[tail])
                return false;
            head++;
            tail--;
        }
        return true;
    }
};