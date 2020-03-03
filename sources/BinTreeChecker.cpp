#include <fstream>
#include <iostream>

#include "../headers/BinTreeChecker.h"

BinTreeChecker::BinTreeChecker() {
    dictionary = new BinTree();
    setMethodName("BinTree");
}

BinTreeChecker::~BinTreeChecker() {
    delete dictionary;
}

bool BinTreeChecker::check(const std::string &word) {
    return BinTree::find(dictionary->root, word);
}

void BinTreeChecker::loadDictionary() {
    std::ifstream fin("../texts/large");
    if (!fin.is_open()) {
        std::cout << "dictionary not open\n";
        return;
    }
    else {
        while (!fin.eof()) {
            std::string word;
            getline(fin, word);

            dictionary->insert(dictionary->root, word);
        }
        fin.close();
    }
}


