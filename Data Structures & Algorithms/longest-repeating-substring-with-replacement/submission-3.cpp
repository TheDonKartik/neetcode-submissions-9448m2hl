class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // if (s.size() == 0) return 0;
        // map <char,int> freq;

        // for (auto i: s){
        //     if (freq.contains(i)) freq[i]++;
        //     else freq[i] = 1;
        // }
        // // copy to a vector
        // vector<pair<int,char>> vec;
        // for (auto i:freq){
        //     vec.push_back({i.second, i.first});
        // }

        // sort(vec.begin(), vec.end(), greater<pair<int,char>>());

        // vector<char> freq_char;
        // freq_char.push_back(vec[0].second);
        // cout << vec[0].second;
        // for (int i = 1; i < vec.size(); i++){
        //     if (vec[i].first == vec[0].first){
        //         freq_char.push_back(vec[i].second);
        //         cout << vec[i].second;
        //         continue;
        //     }
        //     break;
        // }

        unordered_set<char> freq_char (s.begin(),s.end());
        int max = 0;

        for (char most_freq : freq_char){
            int size = 0;
            int util = 0;
            int j = 0;
            for (int i = 0; i < s.size(); i++){
                if (s[i] == most_freq){
                    size++;
                    if (size > max) max = size;
                    continue;  
                }
                // if i is not the most freq element
                // if util < k
                if (util < k){
                    size ++;
                    if (size > max) max = size;
                    util ++;
                    continue;
                }

                // if util = k
                while (s[j] == most_freq){
                    j++;
                    size--;
                }
                j++;
            }
        }

        return max;
    }
};
