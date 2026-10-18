class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            if (!isalnum(s[i])) {i++; continue;}
            if (!isalnum(s[j])) {j--; continue;}
            char c1 = tolower(s[i]);
            char c2 = tolower(s[j]);
            if (c1 != c2)
                return false;
            i++;
            j--;
        }
        return true;
    }
};
