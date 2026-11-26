class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; i++) {
            int x = i;
            int counter = 0;
            while (x > 0) {
                if (x % 2 == 1)
                    counter++;
                x = x / 2;
            }
            result.push_back(counter);
        }
        return result;
    }
};
