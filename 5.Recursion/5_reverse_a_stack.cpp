#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int &temp){
    if(s.size()==1){
        int top = s.top();
        s.push(temp); 
        s.push(top);
        return;
    }
    int value = s.top();
    s.pop();
    insert(s,temp);
    s.push(value);
    return;
}
void reverse(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
}
int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    reverse(s);
    while (!s.empty()) {
        cout << s.top() <<" ";
        s.pop();
    }
    return 0;
}