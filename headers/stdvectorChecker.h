#include <vector>
#include <string>

#include "Checker.h"

#ifndef SPELLER_STDVECTORCHECKER_H
#define SPELLER_STDVECTORCHECKER_H


class StdVectorChecker : public Checker {
public:
    StdVectorChecker();
    ~StdVectorChecker() final;
    bool check(const std::string &) final;
    void loadDictionary() final;

private:
    std::vector<std::string> *dictionary;
};

#endif //SPELLER_STDVECTORCHECKER_H
