class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int need[256] = {0};
        int window[256] = {0};

        for (char c : t) {
            need[(unsigned char)c]++;
        }
        
        int required = 0, formed = 0;
        for (int i = 0; i < 256; i++) {
            if (need[i] > 0)
                required++;
        }

        int L = 0, R = 0;
        int result = INT_MAX;
        int start = 0;
        while (R < s.size()) {
            char c = s[R];
            window[(unsigned char)c]++;

            if (need[(unsigned char)c] > 0 &&
                window[(unsigned char)c] == need[(unsigned char)c])
                formed++;

            while (formed == required) {
                if (R - L + 1 < result) {
                    result = R - L + 1;
                    start = L;
                }

                char left = s[L];
                window[(unsigned char)left]--;

                if (need[(unsigned char)left] > 0 &&
                    window[(unsigned char)left] < need[(unsigned char)left])
                    formed--;
                
                L++;
            }
            R++;
        }
        return result == INT_MAX ? "" : s.substr(start, result); 
    }
};
