class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> a;
        part(0,0,a,s);
        return res;
    }

    void part(int i, int j,vector<string>& a, string& s ){
        if (j >= s.size()){
            if (j==i) res.push_back(a);
            return;
        }

        if ( i == j || ispallindrome(i,j,s)){
            a.push_back(s.substr(i,j-i+1));
            part(j+1,j+1,a,s);
            a.pop_back();
        }

        part(i,j+1, a, s);
    }
    bool ispallindrome(int i, int j, string s){
        if (i == j) return true;
        if (s[i] == s[j]){
            if (i == j+1) return true;
            return ispallindrome(i+1, j-1, s);
        }
        else return false;
    }
};
