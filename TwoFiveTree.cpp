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

}

void twoFiveTree::insert(string word) {

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

void twoFiveTree::getHeight() {

}

void twoFiveTree::preOrder() {

}
