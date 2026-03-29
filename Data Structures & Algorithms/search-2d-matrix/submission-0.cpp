class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix[0].size() - 1;
        int l = 0;
        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][r] < target) continue;
            else if (matrix[i][0] > target) return false;
            else { // target may be in this row
                while(l <= r){
                    int mid = (l+r) / 2;
                    if (matrix[i][mid] == target) return true;
                    else if (matrix[i][mid] > target) r = mid - 1;
                    else l = mid + 1;
                }
            }
        }
        return false;
    }
};
