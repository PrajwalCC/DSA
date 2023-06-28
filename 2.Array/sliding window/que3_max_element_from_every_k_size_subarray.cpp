// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
vector <int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> ans;
    int i=0, j=0;
    map<int,int>m;
    while(j < k){
        m[arr[j]]++;
        j++;
    }
    auto it = m.end();
    it--;
    ans.push_back((*it).first);
    while(j < n){
        if(m[arr[i]] == 1){
            m.erase(arr[i]);
        }
        else{
            m[arr[i]]--;
        }
        m[arr[j]]++;
        it = m.end();
        it--;
        ans.push_back((*it).first);
        i++;
        j++;
    }
    return ans;
}