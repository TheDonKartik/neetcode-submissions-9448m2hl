class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        int flux = -1;
        while(nums[l] > nums[r]){
            int mid = (l+r) / 2;
            if (nums[mid+1] > nums[mid] && nums[mid-1] > nums[mid]) {
                flux = mid;
                break;
            } else if (nums[mid] < nums[r]) r = mid - 1;
            else l = mid + 1;
        }

        if (flux == -1) flux = l;
        cout << flux << endl;;
        if (nums[flux] == target) return flux;

        if (target <= nums[r]) {
            l = flux + 1;
            r = nums.size() -1;
        }else {
            r = (flux == 0)? nums.size() - 1: flux - 1;
            l = 0;
        }



        while(l <= r){
            int mid = (l+r) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
     }
};

