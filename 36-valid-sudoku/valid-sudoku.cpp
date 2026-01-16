class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];

                if (c =='.')
                  continue;
                
                if (!('1' <= c && c <= '9'))
                  return false;
                
                int b = (i/3) * 3 + (j/3);
                int digit_idx = c - '1'; // map to 0-based 0...8

                if (row[i][digit_idx] || col[j][digit_idx] || box[b][digit_idx])
                  return false;
                
                row[i][digit_idx] = true;
                col[j][digit_idx] = true;
                box[b][digit_idx] = true;
            }
        }
        return true;
    }
};