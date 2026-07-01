#include<bits/stdc++.h>
using namespace std ;

struct Node {
   Node *links[26] ;
   bool flag=false ;
   
   bool containChar(char c){
       return (links[c-'a']!=NULL) ;
   }
   void put(char c , Node *node){
       links[c-'a']=node ;
   }
   Node *get(char c){
       return links[c-'a'] ;
   }
   void setEnd(){
       flag=true ;
   }
   bool isEnd(){
       return flag ;
   }
   
};

class Trie{
  private :
  Node *root ;
  
  public :
  Trie(){
      root = new Node() ;
  }
  
  void insert(string word){
      Node *node=root ;
      for(int i=0 ; i<word.length() ; i++){
          if(!node->containChar(word[i])){
              node->put(word[i] , new Node()) ;
          }
          node=node->get(word[i]) ;
      }
      node->setEnd() ;
  }
  bool prefixExists(string word){
      bool flg=true ;
      Node *node=root ;
      for(int i=0 ; i<word.length() ; i++){
          if(node->containChar(word[i])){
              node=node->get(word[i]) ;
              if(node->isEnd()==false) return false ;
          }
          else return false ;
      }
      return true ;
  }
  
};

class Solution {
    public :
    string longestValidWord(vector<string>& words) {
        Trie trie ;
        for(auto &it : words){
            trie.insert(it) ;
        }
        string longest="" ;
        for(auto &it : words){
            if(trie.prefixExists(it)){
                if(it.length()>longest.length()) longest=it ;
                else if(it.length()==longest.length() && it<longest){
                    longest=it ;
                }
            }
        }
        return longest ;
    }
};


int main(){
Solution s ;
vector<string> words={"p", "pr", "pro", "probl", "problem", "pros", "process", "processor"} ;
cout<<s.longestValidWord(words) ;
return 0 ;
}