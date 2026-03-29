class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = 0;
        for (int i : piles){
            if (i > max) max = i;
        }
        int k = max;

        while(min <= max){
            int temp = 0;
            int mid = (min + max) / 2;
            cout << min << " "<< mid << " " << max << endl;

            for(int i : piles){
                temp += ceil( (double)i / mid);
            }
            cout << temp << endl;
            if (temp <= h){
                if (k > mid) k = mid;
                max = mid - 1;
            }else{
                min = mid + 1;
            }
        }

        return k;
    }
};
