#include <iostream>
#include <fstream>
#include "../headers/stdvectorChecker.h"

StdVectorChecker::StdVectorChecker() {
    dictionary = new std::vector<std::string>();
    setMethodName("StdVector");
}

bool StdVectorChecker::check(const std::string &word) {
    for (auto &dictionaryWord : *dictionary) {
        if (word == dictionaryWord) {
            return true;
        }
    }
    return false;
}

void StdVectorChecker::loadDictionary() {
    std::ifstream fin("../texts/large");
    if (!fin.is_open()) {
        std::cout << "dictionary not open\n";
        return;
    }
    else {
        while (!fin.eof()) {
            std::string word;
            getline(fin, word);
            dictionary->push_back(word);
        }
        fin.close();
    }
}

StdVectorChecker::~StdVectorChecker() {
    delete dictionary;
}
