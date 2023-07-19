// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    bool detectCycle(int startingNode, vector<int> adj[], vector<int>& visited){
        queue<pair<int,int>> q;
        q.push({startingNode, startingNode});
        visited[startingNode]=1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacentNodes:adj[node]){
                if(visited[adjacentNodes] == 0){
                    visited[adjacentNodes]=1;
                    q.push({adjacentNodes, node});
                }
                else{
                    if(visited[adjacentNodes] == 1 && adjacentNodes != parent){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){ //for not connect graph,its mandatory to check each node whether it starts cycle or not.
            if(visited[i] == 0){
                if(detectCycle(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends