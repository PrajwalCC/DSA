#include <bits/stdc++.h>
using namespace std;
void solve(string ip, string op){
    if(ip==""){
        cout<<op<<endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back('_');
    op2.push_back(ip[0]);
    op1.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);
}
int main(){
    string ip="abc";
    string op="a";
    ip.erase(ip.begin()+0);
    solve(ip,op);
    return 0;
}