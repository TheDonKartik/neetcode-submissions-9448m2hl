class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_vol = 0;
        for (int i = 0; i < heights.size(); i++){
            for (int j = i+1; j < heights.size(); j++){
                int vol = (j-i)*min(heights[i],heights[j]);
                if (vol > max_vol) max_vol = vol;
            }
        }

        return max_vol;
        
    }
};
