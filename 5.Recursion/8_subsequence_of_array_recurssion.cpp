#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v){
    int n=v.size();
    if(n==0){
        return;
    }
    int temp= v[n-1];
    v.pop_back();
    print(v);
    cout<<temp;
    return;
}
void solve(vector<int> ip, vector<int> op, int i, int n){
    if(i==n){
       print(op);
       cout<<endl;
       return;
    }
    vector<int> op1=op;
    vector<int> op2=op;
    op2.push_back(ip[i]);
    i++;
    solve(ip,op1,i,n);
    solve(ip,op2,i,n);
    return;
}
int main(){
    vector<int> ip;
    ip.push_back(1);
    ip.push_back(2);
    ip.push_back(3);
    vector<int>op;
    int n=ip.size();
    int i=0;
    // print(ip);
    solve(ip,op,i,n);
    return 0;
}