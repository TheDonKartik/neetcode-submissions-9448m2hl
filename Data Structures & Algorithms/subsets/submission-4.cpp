class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int start, vector<int>& nums, vector<int>& path){
        res.push_back(path);

        for (int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path);

            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> initPath;
        backtrack(0, nums, initPath);
        return res;
    }
};
