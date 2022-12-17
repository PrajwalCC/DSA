
#include <bits/stdc++.h>
using namespace std;
int check(vector<int> arr, int sum1, int sum2){
    int n = arr.size();
    if(sum1 == sum2){
        return 0;
    }
    if(n==0){
        return abs(sum1 - sum2);
    }
    int temp = arr[n-1];
    arr.pop_back();
    return min(check(arr,sum1-temp, sum2+temp), check(arr, sum1, sum2));
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int sum1=0;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
        sum1 +=temp;
    }
    int sum2 = 0;
    cout<<check(arr,sum1,sum2);
    return 0;
}