class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        calculate(0,0,{},candidates,target);

        return res;
    }

    void calculate(int i, int sum, vector<int> temp, vector<int> candidates, int target){
        if (target == sum){
            res.push_back(temp);
            return;
        }
        for (int j = i; j < candidates.size(); j++){
            if (j > i && candidates[j] == candidates[j-1]) continue;
            int num = candidates[j];
            if (sum + num > target) return;
            temp.push_back(num);
            calculate(j+1,sum+num,temp,candidates,target);
            temp.pop_back();
        }
    }
};
