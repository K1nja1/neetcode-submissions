class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));

        int n=grid.size();
        int m=grid[0].size();
        int area=0;
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                area=0;
                dfs(i,j,visited,grid,area);
                maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
    void dfs(int i, int j,vector<vector<bool>> &visited,vector<vector<int>> &grid,int &area){
        visited[i][j]=true;
        stack<pair<int,int>> st;
        st.push({i,j});
        area++;
        while(!st.empty()){
        pair<int,int> curr=st.top();
        st.pop();

        i=curr.first;
        j=curr.second;
        
        if(i>0 && grid[i-1][j]==1 && !visited[i-1][j]) {st.push({i-1,j}); visited[i-1][j]=true; area++;}
        if(i<grid.size()-1 && grid[i+1][j]==1 && !visited[i+1][j]) {st.push({i+1,j}); visited[i+1][j]=true;area++;}
        if(j>0 && grid[i][j-1]==1 && !visited[i][j-1]) {st.push({i,j-1}); visited[i][j-1]=true;area++;}
        if(j<grid[0].size()-1 && grid[i][j+1]==1 && !visited[i][j+1]) {st.push({i,j+1}); visited[i][j+1]=true;area++;}

        }

    }

};
