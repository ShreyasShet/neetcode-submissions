class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n, false));
        int result = 0;

        for(int i = 0; i < n; i++) {
            f[i][i] = true;
            result += 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) 
                        f[i][j] = true, result += 1;
                    if (f[i+1][j-1])
                        f[i][j] = true, result += 1;
                }
            }
        }
        return result;
    }
};
