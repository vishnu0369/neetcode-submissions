class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<int>> row(n), col(n), box(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] != '.'){
                    if(!row[i].insert(board[i][j]).second)
                        return false;

                    if(!col[j].insert(board[i][j]).second)
                        return false;

                    int x = (i/3)*3 + j/3;
                    if(!box[x].insert(board[i][j]).second)
                        return false;
                }
            }
        }
        return true;
    }
};
