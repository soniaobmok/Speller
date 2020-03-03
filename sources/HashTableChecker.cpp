#include <fstream>
#include <iostream>

#include "../headers/HashTableChecker.h"

const int CellNumber = 26;
const int CodeOfA = 97;

HashTableChecker::HashTableChecker() {
    dictionary.resize(CellNumber);
    setMethodName("HashTable");
}

bool HashTableChecker::check(const std::string &word) {
    int index = static_cast<int>(word[0]);
    for (auto &item : dictionary[index - CodeOfA]) {
        if (item == word)
            return true;
    }
    return false;
}

void HashTableChecker::loadDictionary() {
    std::ifstream fin("../texts/large");
    if (!fin.is_open()) {
        std::cout << "dictionary not open\n";
        return;
    }
    else {
        while (!fin.eof()) {
            std::string word;
            getline(fin, word);

            int index = static_cast<int>(word[0]) - CodeOfA;
            dictionary[index].push_back(word);
        }
        fin.close();
    }
}
