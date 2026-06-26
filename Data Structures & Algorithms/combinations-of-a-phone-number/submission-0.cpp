class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() )return {};

        vector<string> aplha = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res ={""};
        
        for (char digit : digits) {
            vector<string> tmp;
            for (string &curStr : res) {
                for (char c : aplha[digit - '2']) {
                    tmp.push_back(curStr + c);
                }
            }
            res = tmp;
        }
        return res;
    }
};
