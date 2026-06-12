class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for (int num : nums){
            int size = res.size();
            for (int j = 0; j < size; j++){
                vector<int> temp = res[j];
                temp.push_back(num);
                res.push_back(temp);
            }
        }

        return res;
    }
};
 