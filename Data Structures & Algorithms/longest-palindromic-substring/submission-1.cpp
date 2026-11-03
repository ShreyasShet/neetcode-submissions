class Solution {
public:
    string longestPalindrome(string s) {

        string t = "#";
        for (int c : s) {
            t += c;
            t += "#";
        }

        int n = t.length();
        vector<int> p(n, 0);
        
        int C = 0, R = 0;
        for (int i = 0; i < n; i++) {

            int mirror = 2 * C - i;

            if (i < R) 
                p[i] = min(R - i, p[mirror]);

            while (i + p[i] + 1 < n &&
                i - p[i] - 1 >= 0 &&
                t[i + p[i] + 1] == t[i - p[i] - 1]) {
                
                p[i]++;
            }

            if (i + p[i] > R) 
                C = i, R = i + p[i];
        }

        int center = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
