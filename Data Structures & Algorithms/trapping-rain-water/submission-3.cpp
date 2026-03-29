class Solution {
public:
    int trap(vector<int>& heights) {
        int size = heights.size() - 1;
        vector<int> max_r;
        vector<int> max_l;

        max_r.push_back(heights[0]);
        max_l.push_back(heights[size]);
        for (int i = 1; i < size + 1; i++){
            max_r.push_back(max(max_r[i-1], heights[i]));

            max_l.insert(max_l.begin(), max(max_l[0], heights[size - i]));
        }

        // calculate vol
        int total_vol = 0;
        int vol;
        for (int i = 1; i < size; i++){
            vol =  min (max_r[i-1], max_l[i+1]) - heights[i];

            if (vol>0) total_vol += vol;
            cout << max_r[i] << max_l[i] << vol << endl;
        }

        return total_vol;
    }
};
