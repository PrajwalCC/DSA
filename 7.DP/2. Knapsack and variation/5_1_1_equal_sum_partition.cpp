#include <bits/stdc++.h>
using namespace std;

int equalOrNot(vector<int> arr, int sum1, int sum2){
    int n = arr.size();
    if(n==0){
        return 0;
    }
    if(sum1 == sum2){
        return 1;
    }
    int temp = arr[n-1];
    arr.pop_back();
    return equalOrNot(arr,sum1-temp, sum2+temp) || equalOrNot(arr,sum1, sum2);
}
int check(vector<int> arr){
    int n = arr.size();
    int sum1=0;
    for(int i=0; i<n; i++){
        sum1=sum1+arr[i];
    }
    int sum2 = 0;
    
    return equalOrNot(arr,sum1,sum2);
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
    
    cout<<check(arr);
    return 0;
}