#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> S(nums.begin(), nums.end());
        for(int x : S){
            if (S.find(x-1) != S.end())
                continue;
            
            int current = x;
            int len = 1;

            while(S.find(current+1) != S.end()){
                current++;
                len++;
            }

            result = max(result, len);
        }
        return result;
    }
};
