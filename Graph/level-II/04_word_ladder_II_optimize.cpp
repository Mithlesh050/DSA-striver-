#include<bits/stdc++.h>
using namespace std ;

class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    string b ;
private :
    void dfs(string word , vector<string> &sq){
         if(word==b){
            reverse(sq.begin() , sq.end()) ;
            ans.push_back(sq) ;
            reverse(sq.begin() , sq.end()) ;
            return ;
         }
         string original=word ;
         int step=mp[word] ;
         for (int i = 0; i < word.size(); i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (mp.find(word) != mp.end() && mp[word]+1==step) {
                        sq.push_back(word) ;
                        dfs(word , sq) ;
                        sq.pop_back() ;  
                    }
                }
                word = original;
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord) ;
        b=beginWord ;
        while (!q.empty()) {
            string word = q.front();
            string original = word;
            q.pop();
            if(word==endWord) break ;
            for (int i = 0; i < word.size(); i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (st.find(word) != st.end()) {
                        mp[word] = mp[original] + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word = original;
            }
        }
        if (mp.find(endWord) != mp.end()) {
            vector<string> sq;
            sq.push_back(endWord);
            dfs(endWord, sq);
        }
        return ans;
    }
};

int main(){
    Solution s;
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = s.findLadders(beginWord , endWord , wordList);
    for (int i = 0; i < ans.size(); i++){
        for (auto it : ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }
return 0 ;
}