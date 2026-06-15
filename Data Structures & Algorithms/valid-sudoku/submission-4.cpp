class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            unordered_set<int> st;
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.') continue;
                if(!st.count(board[i][j])) st.insert(board[i][j]);
                else return false;
            }
        }
        for(int i=0;i<board.size();i++){
            unordered_set<int> st;
            for(int j=0;j<board.size();j++){
                if(board[j][i]=='.') continue;
                if(!st.count(board[j][i])) st.insert(board[j][i]);
                else return false;
            }
        }
        for(int i=0;i<board.size();i=i+3){
            for(int j=0;j<board.size();j=j+3){
                unordered_set<int> st;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                            if(board[k][l]=='.') continue;
                            if(!st.count(board[k][l])) st.insert(board[k][l]);
                            else return false;
            
                    }
                }
            }
        }
        return true;
    }
};
