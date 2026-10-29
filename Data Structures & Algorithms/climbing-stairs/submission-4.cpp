class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev1 = 1; //S[0] is 1 because the person is already at 0th step
        for(int i = 2; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
