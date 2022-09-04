#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    stack<int> s;
    vector<int> ans;
    for(int i=0; i<n ;i++){
        cin>>a[i];
    }
    for(int i=0; i<n ;i++){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.size() != 0 && s.top() > a[i]){
            ans.push_back(s.top());
        }
        else{
            while(s.size() != 0 && s.top() < a[i]){
                s.pop();
            }
            if(s.size()==0){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }

        s.push(a[i]);
    }
    
    for(int i=0; i<n ;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}