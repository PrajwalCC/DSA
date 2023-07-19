// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        
        queue<pair<int,int>> q;
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        vector<int> adj[n];
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        q.push({src, 0});
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            dist[node]= min(dist[node], d);
            
            for(auto adjNodes: adj[node]){
                int dAdj = d+1;
                if(dAdj == min(dAdj, dist[adjNodes])){
                    q.push({adjNodes, d+1});
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends