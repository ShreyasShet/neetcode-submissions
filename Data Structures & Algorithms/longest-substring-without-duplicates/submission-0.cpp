class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int n = s.size();
        int L = 0, R = 0, result = 0;
        while (L <= R && R < n) {
            if (lastSeen.find(s[R]) != lastSeen.end()) {
                L = max(L, lastSeen[s[R]] + 1);
            }
            lastSeen[s[R]] = R;
            result = max(result, R - L + 1);
            R++;
        }
        return result;
    }
};
