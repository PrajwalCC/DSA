// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        
        set<pair<int,int>> s;
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        s.insert({0, src});
        while(!s.empty()){
            auto it = s.begin();
            int d = (*it).first;
            int node = (*it).second;
            s.erase(s.begin());
            
            dist[node]= min(dist[node], d);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int weight = it[1];
                int dAdj = d + weight;
                if(dAdj < dist[adjNode]){
                    if(dist[adjNode] != INT_MAX){
                        s.erase({dist[adjNode], adjNode});
                    }
                    s.insert({dAdj, adjNode});
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



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
