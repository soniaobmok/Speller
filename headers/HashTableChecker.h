#include <string>
#include <vector>

#include "Checker.h"

#ifndef SPELLER_HASHTABLECHECKER_H
#define SPELLER_HASHTABLECHECKER_H


class HashTableChecker : public Checker {
public:
    HashTableChecker();
    ~HashTableChecker() = default;
    bool check(const std::string &) final;
    void loadDictionary() final;

private:
    std::vector<std::vector<std::string>> dictionary;
};


#endif //SPELLER_HASHTABLECHECKER_H
