// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands
// can be also done by bfs

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    
    void dfs(int i, int j,int n, int m, vector<vector<char>> grid, vector<vector<int>>& visited, int nrow[], int ncol[]){
        visited[i][j] = 1;
        for(int p=0; p<8; p++){
            int row = i+nrow[p];
            int col = j+ncol[p];
            if(row>=0 && row<n && col>=0 && col < m){
                if(grid[row][col]== '1' && visited[row][col]==0){
                    dfs(row,col,n,m,grid,visited,nrow,ncol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        int nrow[8]={-1,-1,0,1,1,1,0,-1};
        int ncol[8]={0,1,1,1,0,-1,-1,-1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && visited[i][j]==0){
                    count++;
                    dfs(i,j,n,m,grid,visited,nrow,ncol);
                }
            }
        }
        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}