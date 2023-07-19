//https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col, int row0, int col0, vector<vector<int>>& visited, vector<vector<int>>& grid, vector<pair<int,int>>& vec){
        visited[row][col]=1;
        vec.push_back({row - row0, col - col0});
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                if(grid[nrow][ncol]==1 && visited[nrow][ncol]==0){
                    dfs(nrow,ncol,row0,col0,visited,grid,vec);
                }
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        
        map<vector<pair<int,int>>, int> mp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    vector<pair<int,int>> vec;
                    dfs(i,j,i,j,visited,grid,vec);
                    mp[vec]++;
                    
                }
            }
        }
        return mp.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends