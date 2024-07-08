class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;
        for (int numPlayers = 2; numPlayers <= n; ++numPlayers)
            winner = (winner + k) % numPlayers;
        return winner + 1;
    }
};