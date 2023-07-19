// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, int nrow[], int ncol[], vector<vector<int>>& visited, vector<vector<char>>& mat){
        visited[i][j]=1;
        
        for(int p=0; p<4; p++){
            int row = i+nrow[p];
            int col = j+ncol[p];
            
            if(row>=0 && col>=0 && row<mat.size() && col<mat[0].size()){
                if(mat[row][col]=='O' && visited[row][col]==0){
                    visited[row][col]=1;
                    dfs(row,col,nrow,ncol,visited,mat);
                }
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int nrow[4]={-1,0,1,0};
        int ncol[4]={0,1,0,-1};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j == m-1){
                    if(mat[i][j]=='O' && visited[i][j]==0){
                        dfs(i,j,nrow,ncol,visited,mat);
                    }
                }
            }
        }
        vector<vector<char>> ans = mat;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O' && visited[i][j]==0){
                    ans[i][j]='X';
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends