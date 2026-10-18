#include <unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix = nums;
        for(int i = 1; i < nums.size(); i++)
            prefix[i] += prefix[i-1];

        if (nums.size() == 1){
            if (prefix[0] != k)
                return 0;
            else
                return 1;
        }

        unordered_map<int, vector<int>> frequency;
        for(int i = 0; i < prefix.size(); i++)
            frequency[prefix[i]].push_back(i);

        int count = 0;
        for(int i = 0; i < prefix.size(); i++){
            if (prefix[i] == k)
                count++;
            
            int required = prefix[i] - k;
            if (!frequency[required].empty()){
                auto &v = frequency[required];
                int cnt = lower_bound(v.begin(), v.end(), i) - v.begin();
                count += cnt;
                continue;
            }
        }
        return count;
    }
};