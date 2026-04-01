class LRUCache {
public:
    int capacity;
    vector<int> order;
    unordered_map<int,int> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        if (cache.find(key) == cache.end()) return -1;
        erase(order, key);
        order.push_back(key);


        // for(int i = 0; i<order.size();i++) cout << order[i] << " ";
        // cout << endl;
        return cache[key];
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            erase(order, key);
        }else if (order.size() == capacity){
            cache.erase(order[0]);
            order.erase(order.begin());
        }
        order.push_back(key);
        cache[key] = value;

        // for(int i = 0; i<order.size();i++) cout << order[i] << " ";
        // cout << endl;
    }
};
