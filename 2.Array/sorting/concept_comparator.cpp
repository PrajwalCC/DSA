#include <bits/stdc++.h>
using namespace std;
// **trick to remember how to use comparator function** ---> "jaisa chahiye waise return krdoh function",
// increasing order me sort krna hai toh --> return a<b
// for decreasing order return a>b;
// a and b will swap on basis of return value of comaparator function,

bool custom_comparator_increasing_order(int a, int b){
    return a<b;//false ko swap karega, true ko swap nhi karega
}
bool custom_comparator_decreasing_order(int a, int b){
    return a>b;//false ko swap karega, true ko swap nhi karega
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),custom_comparator_increasing_order);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}