class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                S.push(c);
                continue;
            }
            
            if (S.empty())
                return false;
            
            if (c == ')' && S.top() == '(' ||
                c == '}' && S.top() == '{' ||
                c == ']' && S.top() == '[') {
                S.pop();
                continue;
            } else 
                return false;
        }

        return S.empty();
    }
};
