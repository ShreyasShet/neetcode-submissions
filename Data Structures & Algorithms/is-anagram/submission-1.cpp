class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> S;
        for(char c : s)
            S[c]++;
        
        for(char c : t) {
            S[c]--;
            if (S[c] < 0)
                return false;
        }
        return true;
    }
};
