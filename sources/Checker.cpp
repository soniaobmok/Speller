#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include "../headers/Checker.h"

std::string Checker::getWord(const std::string &source) {
    std::string destination;

    for (auto &letter : source) {
        if (!isalpha(letter) && letter != '\'') {
            continue;
        }
        destination.push_back(tolower(letter));
    }

    if (destination[0] == '\'') {
        destination.erase(0);
    }
    if (destination[destination.size() - 1] == '\'') {
        destination.erase(destination.size() - 1);
    }

    return destination;
}

void Checker::loadText(const std::string &address) {
    std::fstream fin(address);
    std::ofstream fout(address + "_" + methodName + ".txt");

    if (!fout.is_open()) {
        std::cout << "file out not open!\n";
    }

    std::string substring;
    int wordsCount = 0;
    int wrongWordsCount = 0;

    for (fin >> substring; !fin.eof(); fin >> substring) {
        std::string word = getWord(substring);
        wordsCount++;

        if (!check(word)) {
            fout << word << std::endl;
            wrongWordsCount++;
        }
    }
    fin.close();
    fout.close();

    checkedWordsNumber += wordsCount;
    wrongWordsNumber += wrongWordsCount;
}

void Checker::loadAllTexts() {
    std::string texts[] = {"../texts/alice.txt"/*, "../texts/dracula.txt", "../texts/holmes.txt",
                           "../texts/sherlock.txt", "../texts/tolstoy.txt"*/};

    for (auto &address : texts) {
        loadText(address);
    }
}

std::string Checker::getMethodName() {
    return methodName;
}

void Checker::setMethodName(const std::string &value) {
    this->methodName = value;
}

int Checker::getCheckedWords() {
    return checkedWordsNumber;
}

int Checker::getWrongWords() {
    return wrongWordsNumber;
}

