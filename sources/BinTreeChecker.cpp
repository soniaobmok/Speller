#include <fstream>
#include <iostream>

#include <vector>
#include <algorithm>
#include <random>

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
        std::vector<std::string> orderedDictionary;
        while (!fin.eof()) {
            std::string word;
            getline(fin, word);

            orderedDictionary.push_back(word);
//            dictionary->insert(dictionary->root, word);
        }
        fin.close();

        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(orderedDictionary), std::end(orderedDictionary), rng);

        for (auto &word :orderedDictionary) {
            dictionary->insert(dictionary->root, word);
        }
    }
}


