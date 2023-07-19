//  https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
      void dfsTopo(int node,vector<pair<int,int>> adj[],vector<int>&visited, stack<int> &s){
          visited[node]=1;
          
          for(auto adjNodes:adj[node]){
              if(visited[adjNodes.first]==0){
                  dfsTopo(adjNodes.first, adj, visited, s);
              }
          }
          s.push(node);
      }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        stack<int> s;
        vector<int>visited(n ,0);
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                dfsTopo(0, adj, visited, s);
            }
        }
        
        vector<int> dist(n, INT_MAX);
        dist[0]=0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            for(auto adjNodes:adj[node]){
                int distNode = dist[node];
                int distAdjNodes = adjNodes.second;
                int totalDist = distNode + distAdjNodes;
                dist[adjNodes.first] = min(dist[adjNodes.first], totalDist);
            }
        }
        for(int i=0; i<n; i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends