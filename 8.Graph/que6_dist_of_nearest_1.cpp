// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> visited(n, vector<int>(m, 0));
	    vector<vector<int>> ans = grid;
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	                visited[i][j]=1;
	                q.push({{i,j}, 0});
	                ans[i][j]=0;
	            }
	        }
	    }
	    int nrow[4]={-1,0,1,0};
	    int ncol[4]={0,1,0,-1};
	    
	    while(!q.empty()){
	        int i = q.front().first.first;
	        int j = q.front().first.second;
	        int dist = q.front().second;
	        q.pop();
	        
	        for(int p=0; p<4; p++){
	            int row = i+nrow[p];
	            int col = j+ncol[p];
	            
	            if(row>=0 && col>=0 && row<n && col<m){
	                if(grid[row][col]==0 && visited[row][col]==0){
	                    visited[row][col]=1;
	                    ans[row][col]=dist+1;
	                    q.push({{row,col},dist+1});
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends