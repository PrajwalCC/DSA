// https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule


#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int n, int p, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> inDegree(n, 0);
	    vector<int> topoSort;
	    
	    queue<int> q;
	    
	    vector<int> adj[n];
	    for(int i=0; i<p; i++){ //CONVERTION of adj list
	        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	    }
	    
	    for(int i=0; i<n; i++){
	        for(auto adjNodes:adj[i]){
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
	        topoSort.push_back(node);
	        
	        for(auto adjNodes:adj[node]){
	            inDegree[adjNodes]--;
	            if(inDegree[adjNodes] == 0){
	                q.push(adjNodes);
	            }
	        }
	        
	    }
	    if(topoSort.size()==n){
	        
    	    return topoSort;
	    }
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends