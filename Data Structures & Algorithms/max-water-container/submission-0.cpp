class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), L = 0, R = n -1;
        int result = min(heights[L], heights[R]) * (R - L);
        while(L < R){
            if (heights[L] < heights[R])
                L++;
            else if (heights[L] > heights[R])
                R--;
            else {
                L++;
                R--;
            }
            int area = min(heights[L], heights[R]) * (R - L);
            if (area > result)
                result = area;        
        }
        return result;
    }
};
