class Solution {
public:
    set<vector<int>> res ;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for (int num:nums){
            set<vector<int>> t;
            for (vector<int> temp : res){
                // vector<int> temp = next(res.begin(),i);
                temp.push_back(num);
                t.insert(temp);
            }
            res.insert(t.begin(), t.end());
            res.insert({num});
        }
        res.insert({{}});
        return vector<vector<int>> (res.begin(), res.end());
    }

};
