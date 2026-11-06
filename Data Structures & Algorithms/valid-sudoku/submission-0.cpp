class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10];
        bool cols[9][10];
        bool box[9][10];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                
                int digit = board[i][j] - '0';
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (rows[i][digit] ||
                    cols[j][digit] ||
                    box[boxIndex][digit])
                        return false;

                rows[i][digit] = true;
                cols[j][digit] = true;
                box[boxIndex][digit] = true;
            }
        }
        return true;
    }
};
