class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int L = 0, R = n-1;
        int leftmax = height[0], rightmax = height[n-1];
        int water = 0;
        while(L < R) {
            leftmax = max(leftmax, height[L]);
            rightmax = max(rightmax, height[R]);

            if (leftmax <= rightmax) {
                water += (leftmax - height[L]);
                L++;
            } else {
                water += (rightmax - height[R]);
                R--;
            }
        }
        return water;
    }
};
