class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int di[4]= {-1,1,0,0};
        int dj[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++) {
                int r=i+di[k];
                int c=j+dj[k];
                if(r<0 || r>=n || c<0 ||c>=m || grid[r][c]<(grid[i][j]+1) ) continue;
                else { grid[r][c]=grid[i][j]+1; q.push({r,c});
            }}

        };
    }
};
