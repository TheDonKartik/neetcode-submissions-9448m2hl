class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > min){
                if (max_profit < prices[i] - min) 
                    max_profit = prices[i] - min;
                continue;
            } 
            min = prices[i];
        }

        return max_profit;
    }
};
