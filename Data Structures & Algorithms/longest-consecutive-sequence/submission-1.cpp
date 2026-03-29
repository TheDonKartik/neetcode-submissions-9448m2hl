class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        if (nums.size() == 0) return 0;
        int max = 1;
        int curr = 1;
        for (int i = 1; i < nums.size(); i++){
            if ( nums[i] == nums[i-1] + 1) curr ++;
            else if (nums[i] == nums[i-1]) ;
            else curr = 1;
            cout << nums[i] << " " << curr << endl;

            if (curr > max) max = curr;
        }

        return max;
    }
};
