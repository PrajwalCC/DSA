#include <bits/stdc++.h>
using namespace std;

int main(){
    int i = 5;
    int& j = i;
    i++;
    cout<<i<<" "<<j<<endl;
    j++;
    cout<<i<<" "<<j<<endl;
    return 0;
}