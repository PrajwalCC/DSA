#include <bits/stdc++.h>
using namespace std;
int sumof(vector<int> op){
    int n = op.size();
    int sum=0;
    for(int i=0; i<n; i++){
        sum=sum+op[i];
    }
    return sum;
}
int check(vector<int> arr, int sum){
    int n = arr.size();
    if(n==0){
        return 0;
    }
    if(sumof(arr) == sum){
        return 1;
    }
    int temp = arr[n-1];
    arr.pop_back();
    return check(arr, sum+temp) + check(arr, sum);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int sum=0;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    // for(int i=0; i<n; i++){
    //     sum=sum+arr[i];
    // }
    
    cout<<check(arr,sum);
    return 0;
}