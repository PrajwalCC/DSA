
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool detectCycle_DFS(int startingNode,int parent, vector<int> adj[], vector<int>& visited){
        
        visited[startingNode]=1;
        for(auto adjacentNodes:adj[startingNode]){
            if(visited[adjacentNodes] == 0){
                visited[adjacentNodes]=1;
                 if(detectCycle_DFS(adjacentNodes, startingNode, adj, visited)){
                     return true;
                 }
            }
            else{
                if(visited[adjacentNodes] == 1 && adjacentNodes != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                if(detectCycle_DFS(i,-1,adj,visited)){
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