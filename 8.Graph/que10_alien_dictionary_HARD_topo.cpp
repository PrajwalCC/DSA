//https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        
        vector<int> adj[k];//creating graph out of que, then will apply toposort
        for(int i=0; i<n-1; i++){
            string s1= dict[i];
            string s2= dict[i+1];
            int j=0;
            while(j<s1.size() && j<s2.size() && s1[j]==s2[j]){
                j++;
            }
            
            if(j<s1.size() && j<s2.size()){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
            }
        }
        
        vector<int> inDegree(k,0);
        for(int i=0; i<k; i++){
            for(auto adjNodes:adj[i]){
                inDegree[adjNodes]++;
            }
        }
        queue<int> q;
        for(int i=0; i<k; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto adjNodes:adj[node]){
                inDegree[adjNodes]--;
                if(inDegree[adjNodes] == 0){
                    q.push(adjNodes);
                }
            }
        }
        
        string s="";
        for(int i=0; i<topo.size(); i++){
            char let = 'a' + topo[i];
            s = s + let;
        }
        
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends