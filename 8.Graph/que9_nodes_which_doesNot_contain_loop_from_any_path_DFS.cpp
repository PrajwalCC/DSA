// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
// Question Name - Eventual Safe States


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool markNoLoop(int node, vector<int>& visited, vector<int>& pathVisited, vector<int> adj[], vector<int>& noLoop){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto adjNodes: adj[node]){
            if(visited[adjNodes]==0){
                if(markNoLoop(adjNodes, visited, pathVisited, adj, noLoop) == true){
                    noLoop[node]=0;//node is mark as 0, becoz its one of path contains loop
                    return true;
                }
            }
            else{
                
                if(pathVisited[adjNodes]==1){
                    noLoop[node]=0;//node is mark as 0, becoz its one of path contains loop
                    return true;//return true which means it contains loop
                }
                
            }
        }
        noLoop[node]=1;//func doesnt break before which means node hasnt have any path which leads to loop
        pathVisited[node]=0;
        return false;//return false which means it doesnot contain any loop
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> noLoop(n , 0);//marking for nodes who donot consist loop, 0->contain loop
        vector<int> visited(n , 0);
        vector<int> pathVisited(n, 0);
        
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                markNoLoop(i,visited,pathVisited,adj,noLoop);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n ;i++){
            if(noLoop[i]==1){
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