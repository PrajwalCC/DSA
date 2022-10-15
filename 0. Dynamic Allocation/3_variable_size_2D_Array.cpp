#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    // creation of 2D Array
    int** arr= new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    // taking inputs
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // giving output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}