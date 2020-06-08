//  AVL Tree.h 

#ifndef AVLTREE_H
#define AVLTREE_H

#include <utility> 
#include <iostream> 
#include <string>

using namespace std; 

class avlTree {
public:

    struct Node {
        string wordVal; 
        int counter; 
        Node *left, *right, *parent; 
        int height; 
    }; 

    Node* newNode(string word); 

    avlTree(); 
    ~avlTree();

    Node* insertDS(string word); 
    Node* insert(string word); 

    void wordSearch(string word); 
    void rangeSearch(string first, string last, Node* n); 


    void printPreOrder(Node* n); 
    void printHeight(); 
    int depth(Node* n); 

    Node *root; 
    
private:
   
    Node* rotateRight(Node* n); 
    Node* rotateLeft(Node* n); 

    int getBalanceFactor(Node *n); 

    Node* insertDSHelper(string word, Node *n); 
    Node* insertHelper(string word, Node *n); 

    int getHeight(Node *n); 

    void clear(Node *n);

};

#endif 