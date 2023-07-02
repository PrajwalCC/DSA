// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
// Striver
vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    queue<int> q;
    vector<int>bfs;
    vector<int> visited(n, 0);
    visited[0]=1;
    q.push(0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for(int i=0; i<adj[node].size(); i++){
            if(visited[adj[node][i]] == 0){
                q.push(adj[node][i]);
                visited[adj[node][i]]=1;
            }
        }
    }
    return bfs;
}