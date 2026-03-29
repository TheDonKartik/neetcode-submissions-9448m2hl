class TimeMap {
public:
    map<string, map<int, string>> timespace;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timespace[key].insert({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        string temp = "";
        for (auto i : timespace[key]){
            if (i.first <= timestamp) temp = i.second;
            else break;
        }
        return temp;
    }
};
