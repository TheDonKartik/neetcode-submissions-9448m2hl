class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        sort(tasks.begin(), tasks.end());
        map<char,int>t;
        for (char c : tasks){
            t[c] +=1;
        }
        int m = 0;
        int n_max = 0;
        for (pair<char,int> i : t){
            if (i.second > m) m= i.second;
        }
        for (pair<char,int> i : t){
            if (i.second == m) n_max++;
        }
        // cout << m << " " << n_max << endl;
        int res = ((m-1) * (n+1)) + n_max;
        int size = tasks.size();
        return max(res, size);
    }
};
