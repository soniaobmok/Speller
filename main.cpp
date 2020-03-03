#include <iostream>
#include <chrono>

#include "headers/stdvectorChecker.h"
#include "headers/HashTableChecker.h"
#include "headers/StdUnorderedSetChecker.h"
#include "headers/BinTreeChecker.h"

int main() {
    auto *checkers = new std::vector<Checker*>();

    auto *stdVectorChecker = new StdVectorChecker();
    auto *hashTableChecker = new HashTableChecker();
    auto *stdUnorderedSetChecker = new StdUnorderedSetChecker();
//    auto *binTreeChecker = new BinTreeChecker();

    checkers->push_back(stdVectorChecker);
    checkers->push_back(hashTableChecker);
    checkers->push_back(stdUnorderedSetChecker);
//    checkers->push_back(binTreeChecker);


    for (auto checker : *checkers) {
        auto loadBegin = std::chrono::steady_clock::now();

        checker->loadDictionary();

        auto loadEnd = std::chrono::steady_clock::now();
        auto loadTime = std::chrono::duration_cast<std::chrono::milliseconds>(loadEnd - loadBegin);

        auto checkBegin = std::chrono::steady_clock::now();

        checker->loadAllTexts();

        auto checkEnd = std::chrono::steady_clock::now();
        auto checkTime = std::chrono::duration_cast<std::chrono::milliseconds>(checkEnd - checkBegin);

        std::cout << std::endl << checker->getMethodName() << " ";
        std::cout << loadTime.count() << " " << checkTime.count() << " ";
        std::cout << checker->getCheckedWords() << " " << checker->getWrongWords();

        delete checker;
    }

    delete checkers;

    return 0;
}
