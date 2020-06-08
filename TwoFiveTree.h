// TwoFiveTree.h

#ifndef TWOFIVETREE_H
#define TWOFIVETREE_H

#include <vector>
#include <iostream>
#include <string>
#include <utility>

using namespace std; 

class twoFiveTree {

public: 

    static const int  Children = 5; 
    struct Node {
        
        pair<string, int> wordArray[Children - 1]; 
        Node** childArray = new Node*[Children]; 
        Node* parent; 
        int keyCount; 
        int pointerCount; 

        ~Node() {
            delete [] childArray; 
        }

        
    }; 

    Node* getRoot() const; 

    twoFiveTree(); 
    ~twoFiveTree(); 

    void searchWord(string word); 
    void rangeSearch(string first, string last, Node* n); 

    void insertDS(string word); 
    void insert(string word); 

    bool fullNode(Node* n); 

    void getHeight();
    void preOrder();

private:

    Node* root; 

    void insertHelper(string word, Node* n); 
    void insertDSHelper(string word, Node* n); 

    void split(string word, Node* n); 
    Node* findPointer(string word, Node* n);
    void insertToNode(string word, Node*n);  

};

#endif 