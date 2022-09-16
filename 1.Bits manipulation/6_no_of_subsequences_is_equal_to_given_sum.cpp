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
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    int n = num.size();
    int target = 7;
        int count = 0;
        for(int i=1; i < pow(2,n); i++){
            vector<int> sub;
            for(int j=0; j<n; j++){
                int check = pow(2,j);
                if(i & check){
                    sub.push_back(num[j]);
                }
            }
            sort(sub.begin(),sub.end());
            int subSize = sub.size();
                
            if((sub[0] + sub[subSize-1]) <= target){
                print(sub);
                cout<<endl;
                count++;
            }
          
        }
        cout<<count;
    return 0;
}