#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int p = 0; p < n; p++)
    {
        cin >> arr[p];
    }
    
    int N = 2e5;
    int idx[N];
    for (int p = 0; p < N; p++)
    {
        idx[p] = -1;
    }
    
    for (int p = 0; p < n; p++)
    {
        if(arr[p]>=0){
         idx[arr[p]] = 1;
        }
    }
    
    for (int p = 0; p < N; p++)
    {
        if (idx[p] == -1)
        {
            cout << p;
            break;
        }
    }
    
    return 0;
}