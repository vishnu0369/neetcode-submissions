class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<int>> row(n), col(n), box(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] != '.'){
                    if(row[i].find(board[i][j]) != row[i].end())
                        return false;
                    else 
                        row[i].insert(board[i][j]);

                    if(col[j].find(board[i][j]) != col[j].end())
                        return false;
                    else
                        col[j].insert(board[i][j]);

                    int x = (i/3)*3 + j/3;
                    if(box[x].find(board[i][j]) != box[x].end())
                        return false;
                    else
                        box[x].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
