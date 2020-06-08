// prog1

#include "AVLtree.h" 
#include "TwoFiveTree.h"
#include <iostream> 
#include <fstream> 
#include <cstdlib>
#include <sstream> 
#include <vector> 

using namespace std; 

int main (int argc, char *argv[]) {
    
    avlTree treeOne; 

    ifstream textFile; 
    textFile.open("/autograder/submission/PA3_dataset.txt"); 
    //textFile.open("PA3_dataset.txt");
    string word; 
    char wordChar[100]; 
    int count; 

    if (textFile.fail()) {
        cerr << "Could not open file 'PA3_dataset.txt'"; 
        exit(1); 
    }

    while (!textFile.eof() && !textFile.fail() && count < 10000) {
        count++; 
        textFile >> wordChar; 
        treeOne.insertDS(wordChar); 
    }
    textFile.close();

    string argument = argv[1] ; 
    string::iterator it = argument.begin(); 
    string subword, sub;  
    vector<string> commands; 

    for (it; it != argument.end(); it++) {
        if (subword.length() > 5)
            sub = subword.substr(subword.length() - 4, 4);  
        if (subword == "search" || subword == "insert" || subword == "range search") {
            commands.push_back(subword); 
            subword.clear();  
        }
        else {
            if(*it == ',') {
                commands.push_back(subword); 
                subword.clear(); 
                it++; 
            }
            else if (sub == " to ") {
                subword = subword.substr(0, subword.length() - 4); 
                commands.push_back(subword); 
                subword.clear(); 
                sub.clear(); 
                subword += *it;  
            }
            else 
                subword += *it; 
        }
    }
    commands.push_back(subword); 
 
    for (int vecIt = 0; vecIt < commands.size(); vecIt++) {  
        if (commands[vecIt] == "range search") {
            treeOne.rangeSearch(commands[vecIt + 1], commands[vecIt + 2], treeOne.root); 
        }
        else if (commands[vecIt] == "insert") {
            treeOne.insert(commands[vecIt + 1]); 
        }
        else if (commands[vecIt] == "search") {
            treeOne.wordSearch(commands[vecIt + 1]); 
        }
    }


}


