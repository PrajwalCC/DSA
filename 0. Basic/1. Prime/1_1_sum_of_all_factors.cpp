// i*(n/i)=36
// 1 36
// 2 18
// 3 12
// 4 9
// 6 6 from here pattern is repeating,so run loop till i*i <=n  
// 9 4
// 12 3 
// 18 2
// 36 1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=36;
    int sum=0;
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            sum=sum+i;
            if((n/i) != i){
                // 6*6 = 36, not to repeat 6 two times we are appling this condition
                sum=sum+(n/i);
            }
        }  
    }
    cout<<sum;
    return 0;
}