#include <fstream>
#include <iostream>

#include "../headers/StdUnorderedSetChecker.h"

StdUnorderedSetChecker::StdUnorderedSetChecker() {
    dictionary = new std::unordered_set<std::string>();
    setMethodName("StdUnorderedSet");
}

StdUnorderedSetChecker::~StdUnorderedSetChecker() {
    delete dictionary;
}

bool StdUnorderedSetChecker::check(const std::string &word) {
    return dictionary->find(word) != dictionary->end();
}

void StdUnorderedSetChecker::loadDictionary() {
    std::ifstream fin("../texts/large");
    if (!fin.is_open()) {
        std::cout << "dictionary not open\n";
        return;
    }
    else {
        while (!fin.eof()) {
            std::string word;
            getline(fin, word);

            dictionary->insert(word);
        }
        fin.close();
    }
}
