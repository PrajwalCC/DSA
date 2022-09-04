#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	int n, m, k;
	while(t--){
	    cin>>n>>m>>k;
	    int a[n], count =0, mex,j=0;
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    for(int i=0; i<n; i++){
	        if(j<a[i]){
	            j++;
	            if(j != a[i]){
	                mex=j;
	                break;
	            }
	        }
            if(i== n-1 && j==0){
                mex=j+1;
                break;
            }
	    }
        cout<<"mex = "<<mex<<endl;
	    if(mex < k){
	        cout<<"NO"<<endl;
	        break;
	    }
	    int p=0;
	    for(int i=0; i<n; i++){
	        if(a[i]<k){
	            count++;
	        }
            if(a[i]==k){
                p++;
            }
	    }
        cout<<"count= "<<count<<endl;
	    if(count<=m && m <= (n-p) ){
	        cout<<"yes"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
