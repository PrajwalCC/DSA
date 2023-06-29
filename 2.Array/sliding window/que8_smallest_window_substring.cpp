// resource aditya verma
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        unordered_map<char, int> mp;
        int minlen=INT_MAX, start=0;
        for(auto ch:t){
            mp[ch]++;
        }
        int i=0,j=0,count=mp.size();
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    count--;
            }
            if(count==0){
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) {
                            count++;
                            if(j-i+1<minlen){
                                minlen=j-i+1;
                                start=i;
                            }
                        }
                    }
                    i++;
                }  
            }
            j++;
        }
        if(minlen==INT_MAX) return "";
        return s.substr(start, minlen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends