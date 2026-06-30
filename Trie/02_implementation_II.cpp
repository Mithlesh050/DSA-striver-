#include<bits/stdc++.h>
using namespace std ;

struct Node {
    Node *links[26] ;
    int cntEndsWith=0 ;
    int cntPrefix=0 ;

    bool containChar(char c){
        return (links[c-'a']!=NULL) ;
    }
    void put(char c , Node *node){
        links[c-'a']=node ;
    }
    Node *get(char c){
        return links[c-'a'] ;
    }
    void incurCEW(){
        cntEndsWith++ ;
    }
    void incurCP(){
        cntPrefix++ ;
    }
    void decreCEW(){
        cntEndsWith-- ;
    }
    void decreCp(){
        cntPrefix-- ;
    }
    int getEnd(){
        return cntEndsWith ;
    }
    int getPrefix(){
        return cntPrefix ;
    }

};

class Trie{
    private :
    Node *root ;

    public :
    Trie(){
        root=new Node() ;
    }

    void insert(string word){
        Node *node=root ;
        for(int i=0 ; i<word.size() ; i++){
            if(!node->containChar(word[i])){
                node->put(word[i] , new Node()) ;
            }
            node=node->get(word[i]) ;
            node->incurCP() ;
        }
        node->incurCEW() ;
    }
    int cntWordsEqualto(string word){
        Node *node=root ;
        for(int i=0 ; i<word.size() ; i++){
            if(node->containChar(word[i])){
                node=node->get(word[i]) ;
            }
            else{
                return 0 ;
            }
        }
        return node->getEnd() ;
    }
    int cntWordsStartingWith(string word){
         Node *node=root ;
        for(int i=0 ; i<word.size() ; i++){
            if(node->containChar(word[i])){
                node=node->get(word[i]) ;
            }
            else{
                return 0 ;
            }
        }
        return node->getPrefix() ;
    }
    void erase(string word){
         Node *node=root ;
        for(int i=0 ; i<word.size() ; i++){
            if(node->containChar(word[i])){
                node=node->get(word[i]) ;
                node->decreCp() ;
            }
            else{
                return  ;
            }
        }
        node->decreCEW() ;
    }

} ;

int main(){
Trie trie ;
trie.insert("apple") ;
trie.insert("apple") ;
cout<<trie.cntWordsEqualto("apple")<<endl ;
trie.insert("appl") ;
cout<<trie.cntWordsStartingWith("app")<<endl ;
trie.erase("apple") ;
cout<<trie.cntWordsEqualto("apple")<<endl ;
return 0 ;
}