class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                dfs(i,j,visited,grid);
                count++;
                }
            }
        }
        return count;

    }
    void dfs(int i, int j,vector<vector<bool>> &visited,vector<vector<char>> grid){
        visited[i][j]=true;
        stack<pair<int,int>> st;
        st.push({i,j});

        while(!st.empty()){
        pair<int,int> curr=st.top();
        st.pop();
        
        i=curr.first;
        j=curr.second;
        visited[i][j]=true;
        if(i>0 && grid[i-1][j]=='1' && !visited[i-1][j]) st.push({i-1,j});
        if(i<grid.size()-1 && grid[i+1][j]=='1' && !visited[i+1][j]) st.push({i+1,j});
        if(j>0 && grid[i][j-1]=='1' && !visited[i][j-1]) st.push({i,j-1});
        if(j<grid[0].size()-1 && grid[i][j+1]=='1' && !visited[i][j+1]) st.push({i,j+1});
        }

    }
};
