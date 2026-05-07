class Solution {
public:
    int getVal(char c) {
        return c - '0';
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, bool> um;
        // Check for all the rows
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int val = getVal(board[i][j]);
                if((val < 1 && val > 9) || (um.count(val) > 0)) return false;
                else um.insert({val, true});
            }
            um.clear();
        }
        // Check for all columns 
        for(int j = 0; j < 9; j++) {
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                int val = getVal(board[i][j]);
                if(um.count(val) > 0) return false;
                else um.insert({val, true});
            }
            um.clear();
        }
        // Check for all the sub boxes 
        for(int i = 0; i < 9;) {
            for(int j = 0; j < 9;) {
                for(int k = i; k < i+3; k++) {
                    for(int l = j; l < j+3; l++) {
                        if(board[k][l] == '.') continue;
                        int val = getVal(board[k][l]);
                        if(um.count(val) > 0) return false;
                        else um[val] = true;
                    }
                }
                um.clear();
                j += 3;
            }
            i += 3;
        }
        return true;
    }
};
