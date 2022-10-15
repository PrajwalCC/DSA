#include <bits/stdc++.h>
using namespace std;
void solve(string ip, string op){
    if(ip==""){
        cout<<op<<endl;
        return;
    }
    string op1=op;
    string op2=op;
    if(isalpha(ip[0])){
        if(isupper(ip[0])){
           op1.push_back(_tolower(ip[0]));
        }
        else{
           op1.push_back(_toupper(ip[0]));
        }
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
    }else{
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1);
    }
   
    
}
int main(){
    string ip = "a3c";
    string op="";
    solve(ip,op);
    return 0;
}