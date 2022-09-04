#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,a;
	    float b;
	    cin>>x;
	    int ans = 0;
	    for(int i=1; i*i < x; i++){
	        a=i;
	        b = (x-(2*a)) % (2 + a);
            int temp = x - (2*a);
	        if(temp == 0 || b != 0){
	            continue;
                cout<<"For i="<<i<<endl;
	        }
	        ans = 1;
	        break;
	    }
	    if(ans== 0){
	        cout<<"N0"<<endl;
	    }else{
	        
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}
