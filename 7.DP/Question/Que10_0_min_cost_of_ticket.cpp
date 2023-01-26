#include <bits/stdc++.h>
using namespace std;
int solve(int day[], int cost[], int i, int n){
    if(i >= n){
        return 0;
    }
    
    // for 1 day
    int a = solve(day,cost,i+1,n) + cost[0];
    
    // for 7days
    int temp = day[i];
    int index;
    for(int j=i; j<n; j++){
        if(day[j] > temp+6){
            index = j;
           break;
        }
        index = j+1;
    }
    int b = solve(day,cost,index,n)+cost[1];

    // for 30days
    temp = day[i];
    for(int j=i; j<n; j++){
        if(day[j] > temp+29){
            index = j;
           break;
        }
        index = j+1;
    }
    int c = solve(day,cost,index,n)+cost[2];
    
    return min(a,min(b,c));
}
int main(){
    int n;
    cin>>n;
    int day[n];
    for(int i=0; i<n; i++){
        cin>>day[i];
    }
    int cost[3];
    for(int i=0; i<3; i++){
        cin>>cost[i];
    }
    cout<<solve(day,cost,0,n);
    return 0;
}