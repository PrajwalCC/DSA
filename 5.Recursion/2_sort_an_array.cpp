#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int &temp){
    if(v.size() == 0 || v[v.size() - 1] <= temp){
        v.push_back(temp);
        return;
    }
    int value = v[v.size() - 1];
    v.pop_back();
    insert(v,temp);
    v.push_back(value);
}
void sort(vector<int> &v){
    if(v.size() == 1){
       return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v,temp); 
}
int main(){
    vector<int> v;
    int n = 5;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}