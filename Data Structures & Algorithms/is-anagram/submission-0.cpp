class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> freq;
        for(int i = 0; i < s.size(); i++)
            freq[s[i]] += 1;
        
        unordered_map<char, int> freq2;
        for(int i = 0; i < t.size(); i++)
            freq2[t[i]] += 1;

        if (freq == freq2)
            return true;
        else
            return false;
    }
};
