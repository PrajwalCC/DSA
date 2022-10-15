//***INPUT*** 
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, int** a, int x, int y){
    if(x<n && y<n && a[x][y] == 1){
        return true;
    }
    return false;
}
bool ratInMaze(int n, int** a, int x, int y, int** sol){
    
    if(x == n-1 && y== n-1){
        sol[x][y]=1;
        return true;
    }
    
    if(isSafe(n, a, x, y)){
        sol[x][y]=1;
        if(ratInMaze(n, a,x+1,y,sol)){
            return true;
        }
        if(ratInMaze(n, a,x,y+1,sol)){
            return true;
        }

        sol[x][y]=0;
        return false;
    }

    return false; 
}

int main(){
    int n = 5;
    // Creation of 2D array -- Dynamic allocation
    int** a = new int*[n];
    for(int i=0; i<n; i++){
        a[i]=new int[n];
    }
    // Taking Inputs
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int** sol = new int*[n];
    for(int i=0; i<n; i++){
        sol[i]=new int[n];
        for(int j=0; j<n; j++){
            sol[i][j]=0;
        }
    }

    if(ratInMaze(n, a,0,0,sol)){ 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<sol[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

