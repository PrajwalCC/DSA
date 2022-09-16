#include <bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int> &s,int &k){
   if(s.size() == k){
     s.pop();
     return;
   }
   int value = s.top();
   s.pop();
   k = s.size();
   deleteMiddle(s,k);
   s.push(value);
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(22);
    s.push(20);
    s.push(50);
    int n  = s.size(),k;
    if(n % 2 == 0){
      k=n/2;
    }else{
      k = (n/2)+1;
    }
    deleteMiddle(s,k);
    while (!s.empty()) {
        cout << s.top() <<" ";
        s.pop();
    }
    return 0;
}