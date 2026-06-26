class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> ndiag;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        place(0,n, board);
        return res;
    }

    void place(int r, int n, vector<string>& board){
        if (r==n){
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++){
            if (cols.count(c) || diag.count(r+c) || ndiag.count(r-c)) continue;

            cols.insert(c);
            diag.insert(r+c);
            ndiag.insert(r-c);
            board[r][c] = 'Q';
            place(r+1, n, board);
            board[r][c] = '.';
            ndiag.erase(r-c);
            diag.erase(r+c);
            cols.erase(c);
        }
    }
};
