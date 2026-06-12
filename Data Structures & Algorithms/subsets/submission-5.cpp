class Solution {
public:
    vector<vector<int>> res;
    void dp(int index, vector<int>& nums, vector<int>& curr){
        res.push_back(curr);
        for(int ptr = index; ptr < nums.size(); ptr++){
            curr.push_back(nums[ptr]);
            dp(ptr + 1, nums, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        dp(0, nums, curr);
        return res;
    }
};
