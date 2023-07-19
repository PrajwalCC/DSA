// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph

// same method is use for undirected graph
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n, INT_MAX);
        dist[0]=0;
        q.push({0, 0});
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            dist[node]= min(dist[node], d);
            
            for(auto adjNodes: adj[node]){
                int dAdj = d+adjNodes.second;
                if(dAdj == min(dAdj, dist[adjNodes.first])){
                    q.push({adjNodes.first, dAdj});
                }
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