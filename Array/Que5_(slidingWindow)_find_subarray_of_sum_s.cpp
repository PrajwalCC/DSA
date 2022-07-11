//Sliding window Technique, where the size of window is variable
// size of window --> size of subarray 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int p=0; p<n;p++){
        cin>>arr[p];
    }
    int s;
    cin>>s;

    int i=0, j=0, curr_sum=0;
     
    while(j<=n){
        if(curr_sum < s){
            curr_sum = curr_sum + arr[j];
             j++;
            
        }
        
        else if(curr_sum == s){
            cout<<i+1<<" "<<j;
            break;
        }
        
        else if(curr_sum > s){
            curr_sum = curr_sum - arr[i];
            i++;
        
           
        }
    }

    return 0;
}