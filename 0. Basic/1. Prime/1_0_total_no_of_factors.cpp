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
// here we can run loop i<=sqrt(n), but T.C of sqrt(n) is log(n),
// so we use i*i <= n, logic is same as i<=sqrt(n)

//*******if count=2 then number is prime*******

// time complexity is O(sqrt(n)), becoz our loop is running till sqrt(n)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=36;
    int count=0;
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            count++;
            cout<<i<<" ";
            if((n/i) != i){
                // 6*6 = 36, not to repeat 6 two times we are appling this condition
                count++;
                cout<<n/i<<endl;
            }
        }  
    }
    cout<<count;
    return 0;
}