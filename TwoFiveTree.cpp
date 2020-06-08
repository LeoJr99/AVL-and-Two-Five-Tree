// TwoFiveTree.cpp

#include "TwoFiveTree.h"

using namespace std;

twoFiveTree::twoFiveTree() : root(nullptr) {} 

twoFiveTree::~twoFiveTree() {
    delete root; 
}

twoFiveTree::Node* twoFiveTree::getRoot() const {
    return root; 
}

bool twoFiveTree::fullNode(Node* n) {
    return n->keyCount == (Children - 1); 
}

void twoFiveTree::searchWord(string word) {
    Node* n = root; 
    int next; 
    while(n) {

        // checks if greater than last key
        if (word > n->wordArray[n->keyCount - 1].first) {
            n = n->childArray[n->keyCount]; 
        }

        // if not, check all keys before it 
        else {
            for (int i = 0; i < n->keyCount; i++) {
                if (word < n->wordArray[i].first) {
                    next = i; 
                    break; 
                }
                else if (word == n->wordArray[i]) {
                    cout << n->wordArray[i].first << " found, count = " 
                         << n->wordArray[i].second << endl; 
                }
            }

            n = n->childArray[next]; 
        }
    }

    cout << word << " not found" << endl; 
}

void twoFiveTree::rangeSearch(string first, string last, Node* n) {
    if (n == nullptr) {
        return; 
    }

    for(int i = 0; i < n->keyCount; i++) {
        if (n->wordArray[i].first >= first && last >= n->wordArray[i].first) {
            cout << n->wordArray[i].first << endl; 
        }

    }

    for (int j = 0; j < n->pointerCount; j++) {
        rangeSearch(first, last, n->childArray[j]); 
    }
}

void twoFiveTree::insert(string word) { // insert & insertDS are similar- with/without cout respectively

}

void twoFiveTree::insertHelper(string word, Node* n) {

}

void twoFiveTree::insertDS(string word) {

}

void twoFiveTree::insertDSHelper(string word, Node* n) {

}

void twoFiveTree::split(string word, Node* n) {

}

twoFiveTree::Node* twoFiveTree::findPointer(string word, Node* n) {

}

void twoFiveTree::insertToNode(string word, Node*n) {

}

// Use : object.getHeight(object.root) 
void twoFiveTree::getHeight(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    int maxH = depth(n->childArray[0]); 
    maxH = maxH + 1;
    cout << "Height = " << maxH << endl; 
}

// Use : object.printPreOrder(object.root) 
void twoFiveTree::printPreOrder(Node* n) {
    if (n==nullptr) {
        return; 
    }

    cout << "("; 
    for(int i = 0; i < n->keyCount; i++) {
        cout << n->wordArray[i].first << ":" << n->wordArray[i].second << ","; 
    }

    for (int j = 0; j < n->pointerCount; j++) {
       printPreOrder(n->childArray[j]); 
    }
    cout << ")";
}
