#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int &temp){
    if(s.empty() || s.top()<=temp){
        s.push(temp);
        return;
    }
    int value = s.top();
    s.pop();
    insert(s,temp);
    s.push(value);
}
void sort(stack<int> &s){
    if(s.size()==1 || s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sort(s);
    insert(s,temp);
}
int main(){
    stack<int> s;
    s.push(5);
    s.push(22);
    s.push(20);
    s.push(50);
    sort(s);
    while (!s.empty()) {
        cout << s.top() <<" ";
        s.pop();
    }
    return 0;
}