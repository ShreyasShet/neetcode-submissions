class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> F(amount + 1, INT_MAX);  //initialize all to INF
        F[0] = 0;       //no possible denomination to get amount = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && F[i - coin] != INT_MAX) //guard against overflow in 1 + INT_MAX
                    F[i] = min(F[i], 1 + F[i - coin]);
            }
        }

        return F[amount] == INT_MAX ? -1 : F[amount];
    }
};
