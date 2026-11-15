class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int L = 0, result = 0, maxFreq = 0;
        for (int R = 0; R < n; R++) {
            freq[s[R]]++;
            maxFreq = max(maxFreq, freq[s[R]]);

            while(R - L + 1 - maxFreq > k) {
                freq[s[L]]--;
                L++;
            }

            result = max(result, R - L + 1);
        }
        return result;
    }
};
