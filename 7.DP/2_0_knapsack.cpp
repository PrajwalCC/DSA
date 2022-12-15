#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapsack(int w[], int v[], int weight, int n){
    if(n==0 || weight==0){
        return 0;
    }

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    if(w[n-1] <= weight){
        return max(v[n-1]+knapsack(w,v,weight-w[n-1],n-1), knapsack(w,v,weight,n-1));
    }
    
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    else{
        return knapsack(w,v,weight,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    int w[n],v[n];
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int weight;
    cin>>weight;
    cout<<knapsack(w,v,weight,n);
    return 0;
}