class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> data;

       for (int i : nums){
        if (data.count(i)){
            return true;
        }
        data.insert(i);
       } 
       return false;
    }
};