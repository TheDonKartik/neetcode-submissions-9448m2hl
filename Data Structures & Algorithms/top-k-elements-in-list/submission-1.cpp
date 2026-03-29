class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int ,int> data;
        vector <pair<int ,int>> temp;
        vector<int> output;
        for (int i : nums){
            data[i]++;
        }

        for (pair<int,int> i : data){
            temp.emplace_back(i.second , i.first);
        }
        
        sort(temp.begin(), temp.end(), greater<pair<int,int>>());
        for (int i = 0; i < k; i++){
            output.emplace_back(temp[i].second);
        }

        return output;
    }
};