class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pos;

        for (int i = 0; i < position.size(); i++){
            pair<int,int> temp;
            temp.first = position[i];
            temp.second = speed[i];

            pos.push_back(temp);
        }

        sort(pos.begin(),pos.end(), greater<pair<int,int>>());
        stack<float> t;
        t.push((target - pos[0].first) / (float)pos[0].second);
        
        for (int i = 1; i < pos.size(); i++){
            float temp = (target - pos[i].first) / (float)pos[i].second;
            // cout << t.top() << endl;
            // cout << temp << endl;
            if (temp > t.top()) t.push(temp);
        }

        return t.size();
    }
};
