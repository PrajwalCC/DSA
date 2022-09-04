#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++ ){
       cin>> a[i];
    }
    stack <pair<int,int>> s;
    vector <int> index;
    for(int i=0; i<n; i++){
        if(s.size() > 0 && s.top().first < a[i]){
           while(s.size() !=0 && s.top().first < a[i]){
            s.pop();
           }  
           if(s.size()==0){
            index.push_back(-1);
           }
           else{
            index.push_back(s.top().second);
           }
        }
        else if(s.size()>0 && s.top().first > a[i]){
            index.push_back(s.top().second);
        }
        else{
            index.push_back(-1);
        }
        s.push({a[i], i});

    }
    
    for(int i=0; i<n ; i++){
        if(index[i] == -1){
            cout<<i+1<<" ";
        }
        else{
            cout<<i - index[i]<<" ";
        }
    }
    return 0;
}