class TriNode {
public:
    TriNode* children[26];
    bool eow;
    TriNode(){
        for (int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        eow = false;
    }
};

class Solution {
public:
    set<string> res;
    vector<vector<bool>> visited;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TriNode* root = new TriNode();
        build(root, words);
        
        for (int i = 0; i < board.size(); i++){
            vector<bool> temp;
            for (int j = 0; j < board[0].size(); j++){
                temp.push_back(false);
            }
            visited.push_back(temp);
        }
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                dfs(i,j,root,board,"");
            }
        }
        return vector<string> (res.begin(), res.end());
    }

    void dfs(int i, int j, TriNode* root, vector<vector<char>>& board, string word){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j])
            return;
        int idx = board[i][j] - 'a';
        
        if (root->children[idx] != nullptr) root = root->children[idx];
        else return;
        visited[i][j] = true;
        word += board[i][j];
        // cout << word << endl;

        if (root->eow) res.insert(word);

        dfs(i-1,j,root,board,word);
        dfs(i+1,j,root,board,word);
        dfs(i,j-1,root,board,word);
        dfs(i,j+1,root,board,word);

        visited[i][j] = false;
    }
    void build(TriNode* root, vector<string>& words){
        for (string word:words){
            TriNode* curr = root;
            for (char c:word) {
                int idx = c-'a';
                if (curr->children[idx] == nullptr) curr->children[idx] = new TriNode();
                curr = curr->children[idx];
            }
            curr->eow = true;
        }
    }
};
