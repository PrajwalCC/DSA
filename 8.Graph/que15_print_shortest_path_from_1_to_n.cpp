// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0; i<m ;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        set<pair<int,int>> s;
        vector<int> dist(n+1, INT_MAX);
        vector<int> lastNode(n+1);
        dist[1]=0;
        s.insert({0, 1});
        
        for(int i=1; i<=n; i++){
            lastNode[i]=i;
        }
        
        while(!s.empty()){
            auto it = s.begin();
            int d = (*it).first;
            int node = (*it).second;
            s.erase(s.begin());
            
            dist[node]= min(dist[node], d);
            
            for(auto value: adj[node]){
                int adjNode = value.first;
                int weight = value.second;
                int dAdj = d + weight;
                if(dAdj < dist[adjNode]){
                    if(dist[adjNode] != INT_MAX){
                        s.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dAdj;
                    s.insert({dAdj, adjNode});
                    lastNode[adjNode]=node;
                }
            }
        }
        vector<int> ans;
        ans.push_back(-1);
        if(dist[n]==INT_MAX) return ans;
        ans.pop_back();
        
        ans.push_back(n);
        int j = lastNode[n];
        while(lastNode[j] != j){
            ans.push_back(j);
            j = lastNode[j];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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