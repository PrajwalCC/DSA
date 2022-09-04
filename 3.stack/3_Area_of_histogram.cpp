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
    stack<pair<int,int>> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            left[i] = - 1;
        }
        else 
        {
            while (!s.empty() && s.top().first > arr[i] )
            {
                s.pop();
            }
            if (s.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = s.top().second;
            }
        }
        s.push({arr[i],i});
    }
    stack<pair<int,int>> p;
    for (int i = n - 1; i >= 0; i--)
    {
        if (p.empty())
        {
            right[i] = -1;
        }
        else
        {
            while (!p.empty() && p.top().first > arr[i])
            {
                p.pop();
            }
            if (p.empty())
            {
                right[i] = -1;
            }
            else
            {
                right[i] = p.top().second;
            }
        }
        p.push({arr[i],i});
    }
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        
        if (right[i] == -1)
        {
            right[i] = n;
        }
        long long int width = right[i] - left[i] - 1;
        ans = max(width*arr[i] , ans);
    }
    
    cout << ans;

    return 0;
}