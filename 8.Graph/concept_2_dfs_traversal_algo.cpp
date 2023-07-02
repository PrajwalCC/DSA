// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
void dfsFunc(int node,vector<int> adj[], vector<int>& visited, vector<int>& dfs){
    visited[node]=1;
    dfs.push_back(node);
    
    for(auto it: adj[node]){
        if(visited[it] == 0){
            dfsFunc(it,adj,visited,dfs);
        }
    }
}
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    int startingNode = 0;
    vector<int> visited(n, 0);
    vector<int> dfs;
    dfsFunc(startingNode, adj, visited, dfs);
    return dfs;
}