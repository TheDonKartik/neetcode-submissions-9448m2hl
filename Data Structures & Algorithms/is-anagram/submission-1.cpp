class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> data;
        
        for (char i : s){
            data.insert(i);
        }
        for (char i : t){
            if(!data.count(i)) return false;
            data.erase(data.find(i));
        }

        if (data.empty()) return true;
        return false;
    }
};
