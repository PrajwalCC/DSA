// https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,int visited[], vector<int> adjList[]){
        visited[node]=1;
        
        for(auto adjNodes: adjList[node]){
            if(visited[adjNodes]==0){
                dfs(adjNodes,visited,adjList);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<int> adjList[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int visited[n]={0};
        int count = 0;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                count++;
                dfs(i,visited,adjList);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends