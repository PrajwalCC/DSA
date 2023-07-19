//https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// DFS

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int startingNode, vector<int>adj[], vector<int>& visited, int prevColor){
	    
	    if(prevColor==1){
	        visited[startingNode]=0;
	    }
	    else{
	        visited[startingNode]=1;
	    }
	    
	    for(auto adjNodes: adj[startingNode]){
	        if(visited[adjNodes]==-1){
	            if(dfs(adjNodes,adj,visited,visited[startingNode])==false){
	                return false;
	            }
	        }
	        else{
	            if(visited[adjNodes] == visited[startingNode]){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	    
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> visited(n, -1);
	    for(int i=0; i<n; i++){
	        if(visited[i]==-1){
	            
	            if(dfs(i,adj,visited,1)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends