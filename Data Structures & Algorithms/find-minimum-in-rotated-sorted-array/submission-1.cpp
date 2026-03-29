class Solution {
public:
    int findMin(vector<int> &nums) {
        int r = nums.size() - 1;
        int l = 0;


        while(nums[l] > nums[r]){
            int mid = (l+r) / 2;
            cout << nums[mid] << endl;
            if (nums[mid+1] > nums[mid] && nums[mid-1] > nums[mid]) return nums[mid];
            else if (nums[mid] < nums[r]) r = mid - 1;
            else l = mid + 1;
    
        }
        return nums[l];
    }
};
