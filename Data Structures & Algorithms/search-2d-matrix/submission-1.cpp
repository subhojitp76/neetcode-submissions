class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()-1, mid, i;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << l << " " << r << endl;
        i = max(min(l, r), 0);  l = 0;  r = matrix[0].size()-1;
        // if(i>=0 && i<matrix[0].size())
        //     return false;
        while(l <= r){
            mid = l + (r - l) / 2;
            cout << mid << " ";
            if(matrix[i][mid] == target)
                return true;
            else if(matrix[i][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};
