class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            swap(nums1,nums2);
        }

        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;
        int l = 0;
        int r = nums1.size();

        while(l<=r){
            int i = (l+r)/2;
            int j = half - i;

            int al = (i > 0) ? nums1[i - 1] : INT_MIN;
            int ar = (i < nums1.size()) ? nums1[i] : INT_MAX;
            int bl = (j > 0) ? nums2[j - 1] : INT_MIN;
            int br = (j < nums2.size()) ? nums2[j] : INT_MAX;
            // int br = nums2[j+1];
            // correct splitting
            cout << i << " " << j << endl;
            cout << al << " " << ar << endl;
            cout << bl << " " << br << endl;
            if (al <= br && bl <= ar){
                if (total % 2 == 0){ // even
                    return ((max(al,bl) + min(ar,br)) / 2.0); 
                }
                return max(al,bl);
            }
            // re-split
            if (al > br) r = i - 1;
            else l = i + 1;
        }
        return -1;
    }
};
