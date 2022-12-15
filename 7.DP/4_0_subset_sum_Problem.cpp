#include <bits/stdc++.h>
using namespace std;
bool checkSum(vector<int> arr, int sum){
    int n = arr.size();
    if(n==0){
        return false;
    }
    if(sum==0){
        return true;
    }
    
    if(arr[n-1] <= sum){
        int temp = arr[n-1];
        arr.pop_back();
        bool ans = checkSum(arr, sum-temp) || checkSum(arr, sum) ;
        return ans;
    }
    else{
        arr.pop_back();
        return checkSum(arr,sum);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
       int temp;
       cin>>temp;
       arr.push_back(temp);
    }
    int sum;
    cin>>sum;
    cout<<checkSum(arr,sum);
    return 0;
}