class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, result = 0;
        int n = s.size();

        vector<int> freq(26, 0);
        int maxFreq = 0;

        for (int R = 0; R < n; R++) {
            int c = s[R] - 'A';
            freq[c]++;

            maxFreq = max(maxFreq, freq[c]);

            while (R - L + 1 - maxFreq > k) {
                freq[s[L] - 'A']--;
                L++;
            }

            result = max(result, R - L + 1);
        }

        return result;
    }
};
