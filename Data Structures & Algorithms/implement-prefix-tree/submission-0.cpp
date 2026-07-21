class TriNode {
public:
    TriNode* children[26];
    bool eow;
    TriNode() {
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        eow = false;
    }
};

class PrefixTree {
public:
    TriNode* root;
    PrefixTree() {
        root = new TriNode();
    }
    
    void insert(string word) {
        TriNode* curr = root;
        for (char c:word){
            int idx = c-'a';
            if (curr ->children[idx] == nullptr)
                curr ->children[idx] = new TriNode();
            curr = curr ->children[idx];
        }
    
        curr->eow = true;
    }
    
    bool search(string word) {
        TriNode* curr = root;
        for (char c:word){
            int idx = c-'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
            // cout << "Found " << c << endl; 
        }
        // cout << "EOW " << curr->eow << endl; 
        if (curr->eow) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TriNode* curr = root;
        for (char c: prefix){
            int idx = c-'a';
            if (curr ->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        
        }
        
        return true;
    }
};
