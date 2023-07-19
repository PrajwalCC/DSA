// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

// concept==> reverse the direction of edges, means change the adj list according to opposition direction of edges
//            then apply toposort, and toposort array will be our ans.



#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> inDegree(n, 0);
	    vector<int> safeElements(n, 0);
	    
	    queue<int> q;
	    vector<int> newAdj[n];
	    for(int i=0; i<n; i++){
	        for(auto adjNodes:adj[i]){
	            newAdj[adjNodes].push_back(i);
	        }
	    }
	    for(int i=0; i<n; i++){
	        for(auto adjNodes:newAdj[i]){
	            inDegree[adjNodes]++;
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        safeElements[node]=1;
	        
	        for(auto adjNodes:newAdj[node]){
	            inDegree[adjNodes]--;
	            if(inDegree[adjNodes] == 0){
	                q.push(adjNodes);
	            }
	        }
	        
	    }
	    
	    vector<int> ans;
	    for(int i=0; i<n; i++){
	        if(safeElements[i]==1){
	            ans.push_back(i);
	        }
	    }
	    return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends