#include<bits/stdc++.h>
using namespace std ;

 vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end()) ;
        queue<vector<string>> q ;
        q.push({beginWord}) ;
        vector<string> usedonlevel ;
        usedonlevel.push_back(beginWord) ;
        int level=0 ;
        vector<vector<string>> ans ;
        while(!q.empty()){
            vector<string> vec=q.front() ;
            q.pop() ;
            if(vec.size()>level){
                level++ ;
                for(auto it : usedonlevel){
                    st.erase(it) ;
                }
                usedonlevel.clear() ;
            }
            string word=vec.back() ;
            if(word==endWord){
                if(ans.size()==0)
                ans.push_back(vec) ;
                else if(ans[0].size()==vec.size())
                ans.push_back(vec) ;
            }
            string original=word ;
            for(int i=0 ; i<word.size() ; i++){
                for(char j='a' ; j<='z' ; j++){
                    word[i]=j ;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word) ;
                        q.push(vec) ;
                        vec.pop_back() ;
                        usedonlevel.push_back(word) ;
                    }
                }
                word=original ;
            }
        }
        return ans ;
    }

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = findLadders(beginWord , endWord , wordList);
    for (int i = 0; i < ans.size(); i++){
        for (auto it : ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }
        return 0;
}