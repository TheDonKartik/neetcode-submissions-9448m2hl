class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        
        sort(nums.begin(),nums.end());
        calculate(0,target,0,nums,temp);
        
        return res;
    }

    void calculate(int i, int target, int sum, vector<int> nums, vector<int>& temp){
        if (sum == target){
            res.push_back(temp);
            return;
        }

        for (int j = i; j < nums.size(); j++){ 
            int num = nums[j];
            if (sum + num > target) return;
            
            temp.push_back(num);
            calculate(j,target,sum + num,nums,temp);
            temp.pop_back();
        }
        
    }
};
