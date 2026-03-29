class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        vector<int> res;
        // find max in starting position
        int curr_max = nums[0];

        for (r = 1; r < k; r++){
            if (nums[r] > curr_max) curr_max = nums[r];
        }
        res.push_back(curr_max);

        for(r = k; r < nums.size(); r++){
            if (nums[l] == curr_max){
                curr_max = nums[l+1];
                for (int i = l+1; i < r + 1; i++){
                    if (nums[i] > curr_max) curr_max = nums[i];
                }
            }else if (nums[r] > curr_max) curr_max = nums[r];
            
            l++;
            res.push_back(curr_max);
        }
        return res;
    }
};
