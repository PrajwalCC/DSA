#include <bits/stdc++.h>
using namespace std;

void solveTower(int source, int helper, int destination, int n, int &count){
    count++;
    if(n==0){
        // cout<<"Moving "<<n<<" plate from "<<source<<" to "<<destination<<endl;
        return;
    }
    solveTower(source,destination,helper, n-1,count);
    cout<<"Moving "<<n<<" plate from "<<source<<" to "<<destination<<endl;
    solveTower(helper,source,destination,n-1,count);
}

int main(){
    int n,count=0;
    cin>>n;
    int source=1, helper=2, destination=3;
    solveTower(source,helper,destination,n, count);
    cout<<"Total no. of steps -> "<<count<<endl;
    return 0;
}