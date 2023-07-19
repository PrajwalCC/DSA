// https://practice.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        map<string, int> m;
        for(int i=0; i<wordList.size() ; i++){
            m[wordList[i]]++;
        }
        queue<pair<string,int>> q;
        q.push({startWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == targetWord){
                return step;
            }
            
            for(int i=0; i< word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(m.find(word) != m.end()){
                        q.push({word, step+1});
                        m[word]--;
                        if(m[word]==0){
                            m.erase(word);
                        }
                    }
                }
                word[i]=original;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends