class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_vol = 0;
        int i = 0;
        int j = heights.size() - 1;
        while(i < j){
            int vol = (j-i)*min(heights[i], heights[j]);
            cout << vol << endl;
            if (vol > max_vol) max_vol = vol;

            if (heights[i] > heights[j]) j--;
            else i++;
        }

        return max_vol;
    }
};
