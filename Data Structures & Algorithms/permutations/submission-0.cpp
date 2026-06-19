class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        insert(0,nums);

        return res;
    }

    void insert(int i, vector<int>& nums){
        int size = nums.size();
        if (i == size){
            res.push_back(nums);
            return;
        }

        for(int j = i; j < size; j++){
            // cout << i << " " << j << endl;
            swap(nums[j],nums[i]);
            insert(i+1,nums);
            swap(nums[i],nums[j]);
        }
    }
};
