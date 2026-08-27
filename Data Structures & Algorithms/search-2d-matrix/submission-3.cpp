class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), l = 0, r = row*col-1;

        while(l <= r) {
            int m = l + (r - l)/2;
            if(matrix[m/col][m%col] == target)
                return true;

            if(matrix[m/col][m%col] < target)
                l = m+1;
            else
                r = m-1;
        }
        return false;
    }
};
