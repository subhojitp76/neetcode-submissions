class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lcol = 0, rcol = matrix[0].size()-1, mcol, trow = 0, brow = matrix.size()-1, mrow;
        while(trow <= brow){
            mrow = trow + (brow - trow) / 2;
            if(matrix[mrow][0] == target)
                return true;
            else if(matrix[mrow][0] < target)
                trow = mrow + 1;
            else{
                brow = mrow - 1;
                mrow = max(0, brow);
            }
        }
        cout << mrow << " " << trow << " " << brow << endl;
        while(lcol <= rcol){
            mcol = lcol + (rcol - lcol) / 2;
            if(matrix[mrow][mcol] == target)
                return true;
            else if(matrix[mrow][mcol] < target)
                lcol = mcol + 1;
            else
                rcol = mcol - 1;
        }
        return false;
    }
};
