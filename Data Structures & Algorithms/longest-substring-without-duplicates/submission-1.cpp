class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> data;

        if (s.size() == 0) return 0;
        data.insert(s[0]);
        int max = 1;
        int size = 1;
        int j = 0;

        for (int i = 1; i < s.size(); i++){
            if (! data.count(s[i])){
                 data.insert(s[i]);
                 size ++;
                 if (size > max) max = size;
                 continue;
            }
            // repeat
            while(s[j] != s[i]){
                data.erase(s[j]);
                j++;
                size --;
            }
            j++;
        }

        return max;
    }
};
