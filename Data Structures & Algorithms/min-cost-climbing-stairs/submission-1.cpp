class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> S(n+1);
        S[0] = 0, S[1] = 0;
        for (int i = 2; i <= n; i++) {
            S[i] = min(S[i-2] + cost[i-2], S[i-1] + cost[i-1]);
        }
        return S[n];
    }
};