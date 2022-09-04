#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left[n], right[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left[i] = 0;
            s.push(arr[i]);
        }
        else 
        {
            while(!s.empty() && s.top() < arr[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = 0;
                s.push(arr[i]);
            }else{
                left[i] = s.top();
            }
        }
        
    }
    stack<int> p;
    for (int i = n - 1; i >= 0; i--)
    {
        if (p.empty())
        {
            right[i] = 0;
            p.push(arr[i]);
        }
        else
        {
            while (!p.empty() && p.top() < arr[i])
            {
                p.pop();
            }
            if (p.empty())
            {
                right[i] = 0;
                p.push(arr[i]);
            }
            else
            {
                right[i] = p.top();
            }
        }
    }
    int h[n],ans=0;
    for(int i=0; i<n; i++){
        h[i] = min(left[i],right[i]);
        if(h[i] != 0){
            int temp = h[i] - arr[i];
            h[i] = temp;
        }
        ans = ans + h[i];
    }

    for(int i=0; i<n; i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<right[i]<<" ";
    // }
    cout<<ans;

    return 0;
}