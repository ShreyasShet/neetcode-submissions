class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m - 1;
        int row = -1;
        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 2;
            if (matrix[mid1][n-1] < target){  //target bigger than elements in row mid1
                lo = mid1 + 1;
            } else if (matrix[mid1][0] > target){  //target lesser than elements in row mid1
                hi = mid1 - 1;
            } else {
                row = mid1;
                break;   
            }
        }

        if (row == -1) return false;
        
        //target possibly within row mid1
        int L = 0, R = n - 1;
        while (L <= R) {
            int mid2 = L + (R - L) / 2;

            if (matrix[row][mid2] == target)
                return true;
            
            if (matrix[row][mid2] < target){
                L = mid2 + 1;
                mid2 = L + (R - L) / 2;
            } else if (matrix[row][mid2] > target){
                R = mid2 - 1;
                mid2 = L + (R - L) / 2;
            } else {
                return false;
            }
        }
        return false;
    }
};
