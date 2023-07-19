//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph 
// done by both bfs and dfs

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[], vector<int> &visited, vector<int> &pathVisited){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto adjNodes:adj[node]){
            if(visited[adjNodes]==0){
                if(dfs(adjNodes,adj,visited,pathVisited)==true){
                    return true;
                }
            }
            else{
                if(pathVisited[adjNodes]==1){
                    return true;
                }
            }
        }
        
        pathVisited[node]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                if(dfs(i,adj,visited,pathVisited)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends