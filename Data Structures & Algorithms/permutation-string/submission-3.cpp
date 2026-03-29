class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) return false;

        map<char,int> freq;

        for(int i = 0; i < s1.size(); i++){
            if (! freq.count(s1[i])) freq[s1[i]] = 1;
            else freq[s1[i]]++;
        }

        for (int i = 0; i < s1.size(); i++){
            if (! freq.count(s2[i])) freq[s2[i]] = 1;
            else freq[s2[i]]--;
            if (! freq[s2[i]]) freq.erase(s2[i]);
        }

        if (freq.empty()) return true;
        int j = 0; 
        for (int i = s1.size(); i < s2.size(); i++){

            if (! freq.count(s2[j])) freq[s2[j]] = 1;
            else freq[s2[j]]--;
            if (! freq[s2[j]]) freq.erase(s2[j]);

            if (! freq.count(s2[i])) freq[s2[i]] = 1;
            else freq[s2[i]] --;
            if (! freq[s2[i]]) freq.erase(s2[i]);

            j++;
            if (freq.empty()) return true;

        }


        return false;
    }
};
