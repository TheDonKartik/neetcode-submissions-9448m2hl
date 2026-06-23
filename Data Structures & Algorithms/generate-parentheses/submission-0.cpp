class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        build(0,0,n,"");
        return res;
    }

    void build(int open,int close, int n, string curr){
        if (close == n){
            res.push_back(curr);
            return;
        }

        if (open < n){
            build(open+1, close,n,curr+"(");
        }

        if (close < open){
            build(open,close+1,n,curr+")");
        }
    }
};
