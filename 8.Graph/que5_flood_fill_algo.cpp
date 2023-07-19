//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& copyData, vector<vector<int>>& image, int newColor,int initialColor, int nrow[], int ncol[]){
        copyData[i][j]= newColor;
        for(int p=0; p<4; p++){
            int row = i+nrow[p];
            int col = j+ncol[p];
            
            if(row>=0 && col>=0 && row<image.size() && col<image[0].size()){
                if(image[row][col]==initialColor && copyData[row][col] != newColor){
                    dfs(row,col,copyData,image,newColor,initialColor,nrow,ncol);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int initialColor = image[sr][sc];
        vector<vector<int>> copyData = image;
        int nrow[4]={-1,0,1,0};
        int ncol[4]={0,1,0,-1};
        dfs(sr, sc, copyData, image, newColor, initialColor, nrow, ncol);
        return copyData;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends