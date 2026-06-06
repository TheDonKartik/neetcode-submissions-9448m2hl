class MedianFinder {
public:
    vector<double> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(),v.end());
    }
    
    double findMedian() {
        int s = v.size();
        if (s%2) return v[s/2];
        return (v[s/2 -1] + v[(s/2)])/2;
    }
};
