#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v){
    if(v.empty()){
        return;
    }
    if(v.size() == 1){
        cout<<v[0]<<" ";
        return ;
    }
    int n = v.size();
    int temp = v[n-1];
    v.pop_back();
    print(v);
    cout<<temp<<" ";
}
int main(){
    vector<int> ip;
    ip.push_back(1);
    ip.push_back(2);
    ip.push_back(3);
    // ip.push_back(4);
    int n = ip.size();
    for(int i=0; i < (1<<n); i++){
        vector<int> sub;
        for(int j=0; j<n ; j++){
            if(i & (1<<j)){
                sub.push_back(ip[j]);
            }
        }
        // print(sub);
        if(sub.size() != 0 ){
            print(sub);
        }
        
        cout<<endl;
    }
    return 0;
}