class TriNode {
public:
    TriNode* children[26];
    bool eow;
    TriNode() {
        for (int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        eow = false;
    }
};

class WordDictionary {
public:
    TriNode* root;
    WordDictionary() {
        root = new TriNode();
    }
    
    void addWord(string word) {
        TriNode* curr = root;

        for (char c:word){
            int idx = c-'a';
            if (curr->children[idx] == nullptr){
                curr->children[idx] = new TriNode();
            }
            curr = curr->children[idx]; 
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        return dfs(word,0, root);
    }

    bool dfs(string word, int idx, TriNode* root){
        TriNode* curr = root;

        if (idx == word.size()){
            // if (word[idx-1] == '.'){
            //     if (curr->eow) return true;
            //     return false;
            // }
            // return true;   
            if (curr->eow) return true;
            return false;
        } 
        if (word[idx] == '.'){
            for (int i = 0; i < 26; i++){
                if (curr->children[i] != nullptr && dfs(word, idx+1,curr->children[i])){
                    return true;
                }
            }
            return false;
        } else {
            int j = word[idx] - 'a';
            if (curr->children[j] == nullptr) return false;
            return dfs(word, idx+1,curr->children[j]);
        }
        
    }   
};
