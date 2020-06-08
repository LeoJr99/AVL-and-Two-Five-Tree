// AVLtree.cpp 

#include "AVLtree.h"
#include <iostream>
#include <algorithm>

using namespace std;

avlTree::avlTree() : root(0) {}

avlTree::~avlTree() {
    clear(root); 
} 

avlTree::Node* avlTree::newNode(string word) {

    Node* n = new Node(); 
    n->wordVal = word; 
    n->counter = 1;
    n->left = nullptr; 
    n->right = nullptr; 
    n->height = 1; 
    return n; 
}

avlTree::Node* avlTree::insertDS(string word) {
    if (!root) {
        root = new Node(); 
        root->wordVal = word; 
        root->counter = 1; 
        root->height = 1; 
        return root; 
    }

    return insertDSHelper(word, root); 
}

avlTree::Node* avlTree::insertDSHelper(string word, Node *n) {
        if(n == nullptr) {
        n = newNode(word);
        return n; 
    }

    if (word == n->wordVal) {
        n->counter = n->counter + 1; 
        return n; 
    }

    else if(word < n->wordVal) {
        n->left = insertDSHelper(word, n->left); 
    }

    else if(word > n->wordVal) {
        n->right = insertDSHelper(word, n->right); 
    }

    n->height = 1 + max(getHeight(n->left), getHeight(n->right)); 

    int balance = getBalanceFactor(n);        //get balance factor
   
    // rotate if unbalanced 
   
    // Left Left Case  
    if (balance > 2 && word < n->left->wordVal) {
        return rotateRight(n);  
    }
   
    // Right Right Case  
    if (balance < -2 && word > n->right->wordVal)  {
        return rotateLeft(n);  
    }

    // Left Right Case  
    if (balance > 2 && word > n->left->wordVal)  
    {  
        n->left = rotateLeft(n->left);  
        n = rotateRight(n);  
        return n; 
    }  
   
    // Right Left Case  
    if (balance < -2 && word < n->right->wordVal)  
    {  
        n->right = rotateRight(n->right);  
        n = rotateLeft(n);  
        return n; 
    }  

    return n;
}

avlTree::Node* avlTree::insert(string word) {
    if (!root) {
        root = new Node(); 
        root->wordVal = word; 
        root->counter = 1;  
        root->height = 1;

        cout << word << " inserted, new count = " << root->counter << endl;

        return root; 
    }

    return insertHelper(word, root);
}

avlTree::Node* avlTree::insertHelper(string word, Node *n) {

    if(n == nullptr) {
        n = newNode(word);
        cout << word << " inserted, new count = " << n->counter << endl; 
        return n; 
    }

    if (word == n->wordVal) {
        n->counter = n->counter + 1; 
        cout << word << " inserted, new count = " << n->counter << endl; 
        return n; 
    }

    else if(word < n->wordVal) {
        n->left = insertHelper(word, n->left); 
    }

    else if(word > n->wordVal) {
        n->right = insertHelper(word, n->right); 
    }

    n->height = 1 + max(getHeight(n->left), getHeight(n->right)); 

    int balance = getBalanceFactor(n);        //get balance factor
   
    // rotate if unbalanced 
   
    // Left Left Case  
    if (balance > 2 && word < n->left->wordVal) {
        return rotateRight(n);  
    }
   
    // Right Right Case  
    if (balance < -2 && word > n->right->wordVal)  {
        return rotateLeft(n);  
    }

    // Left Right Case  
    if (balance > 2 && word > n->left->wordVal)  
    {  
        n->left = rotateLeft(n->left);  
        n = rotateRight(n);  
        return n; 
    }  
   
    // Right Left Case  
    if (balance < -2 && word < n->right->wordVal)  
    {  
        n->right = rotateRight(n->right);  
        n = rotateLeft(n);  
        return n; 
    }  

    return n;  

}

avlTree::Node* avlTree::rotateRight(Node* n) {

    Node* x = n->left; 
    Node* subTree = x->right; 

    if (n == root) {
        root = x; 
    }

    x->right = n; 
    n->parent = x; 
    n->left = subTree;

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 

    return x; 
}

avlTree::Node* avlTree::rotateLeft(Node *n) {

    Node* y = n->right; 
    Node* subTree = y->left; 

    if (n == root) {
        root = y; 
    }

    y->parent = n->parent; 
    y->left = n; 
    n->parent = y; 
    n->right = subTree; 

    n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; 
}

int avlTree::getHeight(Node *n) {
    if (n == nullptr) {
        return 0; 
    }
    return n->height; 
}

int avlTree::getBalanceFactor(Node *n) {
    if (n==nullptr) {
        return 0; 
    }
    return depth(n->left) - depth(n->right); 
}

void avlTree::rangeSearch(string first, string last, Node* n) {
    if (n == nullptr) {
        return; 
    }

    if (first < n->wordVal) {
        rangeSearch(first, last, n->left);
    }

    if (first <= n->wordVal && last >= n->wordVal) {
        cout << n->wordVal << endl; 
    }

    if (last > n->wordVal) {
        rangeSearch(first, last, n->right); 
    }
}

void avlTree::wordSearch(string word) {
    Node* n = root; 

    while(n) {
        if (word > n->wordVal) {
            n = n->right; 
        }
        else if (word < n->wordVal) {
            n = n->left; 
        }
        else if (word == n->wordVal) {
            cout << word << " found, count = " << n->counter << endl; 
            return; 
        }
    }
    cout << word << " not found" << endl; 
}

void avlTree::printHeight() {
    int maxHeight; 
    maxHeight = depth(root); 
    cout << maxHeight << endl; 
}

void avlTree::printPreOrder(Node *n) {
    if (n == nullptr) {
        return;
    }
  
    cout << n->wordVal << " "; 
    printPreOrder(n->left);  
    printPreOrder(n->right); 

}

void avlTree::clear(Node* n) {

    if(n) {
        clear(n->left); 
        clear(n->right); 
        delete n; 
    }
}

int avlTree::depth(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    int maxLeft = depth(n->left); 
    int maxRight = depth(n->right); 
    int maxH = max(maxLeft, maxRight) + 1;
    return maxH; 
}