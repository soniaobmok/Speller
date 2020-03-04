#include <string>

#include "Checker.h"
#include "bintree.h"

#ifndef SPELLER_BINTREECHECKER_H
#define SPELLER_BINTREECHECKER_H


class BinTreeChecker : public Checker {
public:
    BinTreeChecker();
    ~BinTreeChecker() final;
    bool check(const std::string &) final;
    void loadDictionary() final;

private:
    BinTree *dictionary;
};


#endif //SPELLER_BINTREECHECKER_H
