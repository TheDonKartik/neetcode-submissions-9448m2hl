class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        for (string i : strs){
            output += to_string(i.size());
            output += ":";
            output += i;
        }
        return output;
    }
    
    vector<string> decode(string s) {
        string size;
        vector<string> output;
        int n ;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ':'){
                size += s[i];
                continue;
            }
            // found :
            n = stoi(size);
            output.emplace_back(s.substr(i+1, n));
            i += n;
            size = "";
        }
        return output;
    }
};
