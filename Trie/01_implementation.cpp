#include<bits/stdc++.h>
using namespace std ;

struct Node{
    Node *links[26] ;
    bool flag=false ;
    bool containsChar(char c){
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
} ;

class Trie {
private :
    Node *root ;
public:
    Trie() {
       root=new Node() ;
    }
    
    void insert(string word) {
        Node *node=root ;
        for(int i=0 ; i<word.length() ; i++){
            if(!node->containsChar(word[i])){
                node->put(word[i] , new Node()) ;
            }
            node = node->get(word[i]) ;
        }
       node->setEnd() ;
    }
    
    bool search(string word) {
        Node *node=root ;
        for(int i=0 ; i<word.length() ; i++){
            if(!node->containsChar(word[i])) return false ;
            node=node->get(word[i]) ;
        }
        return node->isEnd() ;
    }
    
    bool startsWith(string prefix) {
        Node *node=root ;
        for(int i=0 ; i<prefix.length() ; i++){
            if(!node->containsChar(prefix[i])) return false ;
            node=node->get(prefix[i]) ;
        }
        return true ;
    }
};


int main(){
Trie trie = Trie();
trie.insert("apple");
cout<<trie.search("apple")<<endl;  
cout<<trie.search("app")<<endl;     
cout<<trie.startsWith("app")<<endl;
trie.insert("app");
cout<<trie.search("app")<<endl; 
return 0 ;
}