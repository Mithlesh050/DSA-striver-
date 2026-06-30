#include<bits/stdc++.h>
using namespace std ;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin() , wordList.end()) ;
        queue<pair<string , int>> q ;
        q.push({beginWord , 1}) ;
        while(!q.empty()){
            string node=q.front().first ;
            int count=q.front().second ;
            q.pop() ;
            if(node==endWord) return count ;
            string original=node ;
            for(int i=0 ; i<node.length() ; i++){
                for(char j='a' ; j<='z' ; j++){
                   node[i]=j ;
                   if(st.find(node)!=st.end()){
                    st.erase(node) ;
                    q.push({node , count+1}) ;
                   }
                }
                node=original ;
            }
        }
        return 0 ;
    }

int main(){
string beginWord = "hit", endWord = "cog" ;
vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
cout << ladderLength(beginWord, endWord , wordList);
return 0 ;
}