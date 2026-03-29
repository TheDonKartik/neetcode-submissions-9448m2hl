class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        map<char,int> freq;
        map<char,int> curr;

        for(int i = 0; i < s1.size(); i++){
            if (! freq.count(s1[i])) freq[s1[i]] = 1;
            else freq[s1[i]]++;

            if (! curr.count(s2[i])) curr[s2[i]] = 1;
            else curr[s2[i]] ++;
        }

        if (freq == curr) return true;
        int j = 0;
        for (int i = s1.size(); i < s2.size(); i++){
            curr[s2[j]]--;
            if (! curr[s2[j]]) curr.erase(s2[j]);
            j++;

            if (! curr.count(s2[i])) curr[s2[i]] = 1;
            else curr[s2[i]] ++;

            if (freq == curr) return true;
        }


        return false;
    }
};
