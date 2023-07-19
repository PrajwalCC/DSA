//https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> inDegree(n, 0);
	    vector<int> topoSort;
	    
	    queue<int> q;
	    
	    vector<int> adj[n];
	    for(int i=0; i<p; i++){ //CONVERTION of adj list
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
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
	    
	    if(topoSort.size()<n){
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends