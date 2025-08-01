#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node * links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;


    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node * node) {

        links[ch - 'a'] = node;
    }

    Node * get(char ch){
        return links[ch - 'a'];
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increaseprefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEndWith;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node * node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increaseprefix();
        }
        node->increaseEnd();
    }

    
    int countWordsEqualTo(string &word){
        Node * node = root;
        for(int  i = 0 ;i < word.length(); i ++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node * node = root;
        for(int  i = 0 ;i < word.length(); i ++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        if(countWordsEqualTo(word) > 0){
            Node * node = root;
            for(int  i = 0 ;i < word.length(); i ++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                    node->reducePrefix();
                }
            }
            node->deleteEnd();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}