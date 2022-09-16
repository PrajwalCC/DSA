#include <bits/stdc++.h>
using namespace std;
// void print(vector<int> v){
//     if(v.empty()){
//         return;
//     }
//     if(v.size() == 1){
//         cout<<v[0]<<" ";
//         return ;
//     }
//     int n = v.size();
//     int temp = v[n-1];
//     v.pop_back();
//     print(v);
//     cout<<temp<<" ";
// }
bool cal(vector<int> v,int x){
    int n = v.size();
    if(n==0){
        return false;
    }
    float sum=0;
    for(int i=0; i<n; i++){
        sum+=v[i];
    }
    float check = sum/n;
    if(check == x){
        return true;
    }
    return false;
}
void solve(vector<int> ip, vector<int> op, int n, int i,int x, int &count){
   if(i == n){
      if(cal(op,x)){
        count++;
      }
      return;
   }
   vector<int> op1 = op;
   vector<int> op2 = op;
   op2.push_back(ip[i]);
   i++;
   solve(ip,op1,n,i,x,count);
   solve(ip,op2,n,i,x,count);
   return;
}
int main(){
    vector<int> ip;
    ip.push_back(7);
    ip.push_back(9);
    ip.push_back(8);
    ip.push_back(9);
    vector<int> op;
    int n = ip.size();
    int i=0;
    int x=8;
    int count=0;
    solve(ip,op,n,i,x,count);
    cout<<count;
    return 0;
}