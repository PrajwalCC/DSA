// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> freq(n, 0);
        vector<int> topoSort;
        queue<int> q;
        for(int i=0; i<n; i++){
            for(auto adjNodes:adj[i]){
                freq[adjNodes]++;
            }
        }
        for(int i=0; i<n; i++){
            if(freq[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            
            for(auto adjNodes:adj[node]){
                freq[adjNodes]--;
                if(freq[adjNodes]==0){
                    q.push(adjNodes);
                }
            }
        }
        
        if(topoSort.size()<n){
            return true;
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