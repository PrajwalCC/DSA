#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int unboundedKnapsack(int w[], int v[], int weight, int n){
    if(n==0 || weight==0){
        return 0;
    }
    //  **(diff betw bounded and unbounded knapsack lies in point 1)***
    // Return the maximum of two cases:
    // (1)if nth item included, then dont remove that element from array... that included element may include further
    // (2)if nth item not included, then remove that element from array..becoz once we have decide to not to take element then definitely we are not going to take it further
    if(w[n-1] <= weight){
        return max(v[n-1]+unboundedKnapsack(w,v,weight-w[n-1],n), unboundedKnapsack(w,v,weight,n-1));
    }
    
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    else{
        return unboundedKnapsack(w,v,weight,n-1);
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
    cout<<unboundedKnapsack(w,v,weight,n);
    return 0;
}