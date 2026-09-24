class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = n - 1, row, col;
        while(i <= j){
            row = (i + j) / 2;
            if(matrix[row][0] == target)
                return true;
            else if(matrix[row][0] > target)
                j = row - 1;
            else
                i = row + 1;
        }
        row = max(min(i, j), 0);
        i = 0, j = m - 1;
        while(i <= j){
            col = (i + j) / 2;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                i = col + 1;
            else
                j = col - 1;
        }
        return false;
    }
};
