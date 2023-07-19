// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int visited[n][m];
    int freshCount=0;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }
            else{
                visited[i][j]=0;
            }
            
            if(grid[i][j] == 1){
                freshCount++;
            }
        }
    }
    
    int tmax = 0;
    int nrow[] = {-1,0,1,0};
    int ncol[] = {0,1,0,-1};
    int count = 0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t   = q.front().second;
        tmax = max(tmax, t);
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int urow = row+ nrow[i];
            int ucol = col+ ncol[i];
            if(urow>=0 && urow<n && ucol>=0 && ucol<m){
                if(grid[urow][ucol]==1 && visited[urow][ucol]!=2){
                    visited[urow][ucol]=2;
                    q.push({{urow,ucol},t+1});
                    count++;
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(grid[i][j]==1 && visited[i][j] != 2){
    //             return -1;
    //         }
    //     }
    // }
    // return tmax;
    // OR
    if(freshCount != count){
        return -1;
    }
    else{
        return tmax;
    }
}