class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        for (string i : strs){
            output += to_string(i.size());
            output += ":";
            output += i;
        }
        cout << output << endl; 
        return output;
    }
    
    vector<string> decode(string s) {
        string temp, size;
        vector<string> output;
        
        int n = 0;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ':'){
                size += s[i];
                continue;
            }
            // found :
            n = stoi(size);
            cout << n << endl;
            for (int j = i + 1; j < i + n + 1; j++){
                temp += s[j];
            }
            i += n;
            cout << temp << endl;
            output.emplace_back(temp);
            temp = "";
            size = "";
        }
        return output;
    }
};
