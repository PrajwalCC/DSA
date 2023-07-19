// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// BFS

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int startingNode, vector<int>adj[],vector<int>& visited){
        queue<pair<int,int>> q;
	    q.push({startingNode,1});
	    visited[startingNode]=1;
	    
	    while(!q.empty()){
	        int node = q.front().first;
	        int colour = q.front().second;
	        q.pop();
	        
	        for(auto adjNodes: adj[node]){
	            if(visited[adjNodes]== -1){
	                if(colour==0){
	                    visited[adjNodes]=1;
	                    q.push({adjNodes, 1});
	                }
	                else{
	                    visited[adjNodes]=0;
	                    q.push({adjNodes, 0});
	                }
	            }
	            else{
	                if(colour==visited[adjNodes]){
	                    return false;
	                }
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
	            if(check(i,adj,visited)==false){
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