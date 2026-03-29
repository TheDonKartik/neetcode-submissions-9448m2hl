class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> output;
        for (int i = 0; i < strs.size(); i++){
            vector<string> temp;
            string t = strs[i];
            sort(t.begin(), t.end());
            cout << t << endl;
            temp.emplace_back(strs[i]);

            for(int j = i+1; j < strs.size(); j++){
                string n = strs[j];
                sort(n.begin(), n.end());
                if ( n == t){
                    temp.emplace_back(strs[j]);
                    strs.erase(strs.begin() + j);
                    j--;
                }
            }
            strs.erase(strs.begin() + i);
            i--;
            output.emplace_back(temp);
        }
        return output;
    }
    
};
