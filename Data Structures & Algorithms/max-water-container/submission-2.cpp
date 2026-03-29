class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max_vol= 0;
        int i = 0;
        int vol;
        int j = heights.size() - 1;
        while(i < j){
            if (heights[i] > heights[j]){
                vol = (j-i)*heights[j];
                j--;
            } else {
                vol = (j-i)*heights[i];
                i++;
            }
            cout << vol << endl;
            if (vol > max_vol) max_vol = vol;
        }

        return max_vol;
    }
};
