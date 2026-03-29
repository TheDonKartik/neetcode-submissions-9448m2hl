class TimeMap {
public:
    map<string, map<int, string>> timespace;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timespace[key].insert({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        // map<string, map<int,string>> temp;
        auto options = timespace[key];
        string temp = "";
        for (auto i : options){
            if (i.first <= timestamp) temp = i.second;
            else break;
        }
        return temp;
    }
};
