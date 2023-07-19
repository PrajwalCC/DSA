// https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       
        queue<vector<string>> q;
        // unordered_m<string,int> m;
        // for(int i=0; i<wordList.size(); i++){
        //     m[wordList[i]]++;
        // }
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        q.push(usedOnLevel);
        
        vector<vector<string>> ans;
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
            string word = vec.back();
            
            // storing answer
            if(word == endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            
            // erasing elements from map, level wise...
            if(vec.size()>level){
                level++;
                for(int i=0; i<usedOnLevel.size(); i++){
                    // m[usedOnLevel[i]]--;
                    // if(m[usedOnLevel[i]] == 0){
                    //     m.erase(usedOnLevel[i]);
                    // }
                    st.erase(usedOnLevel[i]);
                }
                usedOnLevel.clear();
            }
            
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        usedOnLevel.push_back(word);
                    }
                }
                word[i]=original;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends