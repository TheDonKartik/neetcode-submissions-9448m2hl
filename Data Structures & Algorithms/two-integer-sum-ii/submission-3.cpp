class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> output;
        for (int i = 0; i < numbers.size(); i++){

            if (numbers[i] + numbers[numbers.size()-1] < target){
                continue;
            }       
            for (int j = numbers.size() - 1; j > i; j--){
                if (numbers[i] + numbers[j] == target){
                    output.emplace_back(i + 1);
                    output.emplace_back(j + 1);
                    return output;
                }
            }
        }
    }
};
