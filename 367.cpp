//word ladder (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>s(wordList.begin(),wordList.end()); //put wordlist in set
        //make a queue for bfs traversal
                 //word   steps
        queue<pair<string,int>>q;
        //push startWord in queue along w its steps ie 1
        q.push({startWord,1});
        s.erase(startWord);
        
        //do bfs traversal
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==targetWord)
            {
                return steps;
            }
            //har word ke saare chars traverse kro
            for(int i=0;i<word.size();i++)
            {
                char original=word[i]; //jo word ka original letter hai
                //ab word ke har char ko change krke dekho from a to z
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    //if this new word after replacing original char exists in set then erase it from
                    //set and push it in queue and increment step size
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push(make_pair(word,(steps+1)));
                    }
                }
                //ab jo changed letter that usko phirse original mein convert kro for next iteration
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