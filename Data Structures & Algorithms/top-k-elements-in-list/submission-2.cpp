class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int ,int> data;
        // priority_queue <pair<int ,int>, greater<pair<int,int>>> temp;
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
        vector<int> output;
        for (int i : nums){
            data[i]++;
        }

        for (pair<int,int> i : data){
            temp.push({i.second , i.first});
            if (temp.size() > k) temp.pop();
        }
        
        // sort(temp.begin(), temp.end(), greater<pair<int,int>>());
        for (int i = 0; i < k; i++){
            output.emplace_back(temp.top().second);
            temp.pop();
        }


        return output;
    }
};