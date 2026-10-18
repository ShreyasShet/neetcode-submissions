#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;
        for(int i = 0; i < nums.size(); i++)
            freq[nums[i]].push_back(i);

        for(int i = 0; i < nums.size(); i++){
            if (freq[nums[i]].size() != 1)
                return true;
        }
        return false;
    }
};