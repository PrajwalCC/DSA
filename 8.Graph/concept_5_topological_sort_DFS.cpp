// https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

// taking in consideration the graph 1->2->3->4
// we start with the dfs(1) we keep calling it for the adjacent nodes and at the very end we reach dfs(4) WHICH DOES NOT HAS ANY ADJ NODE,
// thus we put it in the stack stating that there is no node it needs to point after completion we push 3 in the stack stating that all the nodes pointed by 3 must already be the stack,
// same way we go up and at the end we push 1 in the stack stating that all the nodes pointed by 1 are already in the stack in a linear order.
// Linear order if a node v points to u then v comes first then u.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node, vector<int> adj[], vector<int>& visited, stack<int> &s){
	    visited[node]=1;
	    
	    for(auto adjNodes: adj[node]){
	        if(visited[adjNodes]==0){
	            dfs(adjNodes,adj,visited,s);
	        }
	    }
        s.push(node);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> visited(n, 0);
	    stack<int> s;
	    
	    for(int i=0; i<n; i++){
	        if(visited[i]==0){
	            dfs(i,adj,visited,s);
	        }
	    }
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends