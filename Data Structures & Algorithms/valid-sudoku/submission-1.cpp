class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set <int> row, col, b1, b2, b3, b4, b5, b6, b7, b8, b9;

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                // check for col
                if (board[j][i] != '.'){
                    if (col.count(board[j][i])) return false;
                    else col.insert(board[j][i]);
                }
                // check for '.'
                if (board[i][j] == '.') continue;  
                // check for row
                if (row.count(board[i][j])) return false;
                else row.insert(board[i][j]);

                if (i >= 0 && i <= 2){
                    if (j >=0 && j <= 2){
                        if (b1.count(board[i][j])) return false;
                        else b1.insert(board[i][j]);
                    }else if (j >= 3 && j <= 5){
                        if (b2.count(board[i][j])) return false;
                        else b2.insert(board[i][j]);
                    }else {
                        if (b3.count(board[i][j])) return false;
                        else b3.insert(board[i][j]);
                    }
                }else if(i >= 3 && i <= 5){
                    if (j >=0 && j <= 2){
                        if (b4.count(board[i][j])) return false;
                        else b4.insert(board[i][j]);
                    }else if (j >= 3 && j <= 5){
                        if (b5.count(board[i][j])) return false;
                        else b5.insert(board[i][j]);
                    }else {
                        if (b6.count(board[i][j])) return false;
                        else b6.insert(board[i][j]);
                    }
                }else{
                    if (j >=0 && j <= 2){
                        if (b7.count(board[i][j])) return false;
                        else b7.insert(board[i][j]);
                    }else if (j >= 3 && j <= 5){
                        if (b8.count(board[i][j])) return false;
                        else b8.insert(board[i][j]);
                    }else {
                        if (b9.count(board[i][j])) return false;
                        else b9.insert(board[i][j]);             
                    }
                }
            }
            cout << "Cleared row " << i << endl;
            col.clear();
            row.clear();
        }

        return true;
    }
};
