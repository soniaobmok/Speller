#include <string>
#include <unordered_set>
#include "Checker.h"

#ifndef SPELLER_STDUNORDEREDSETCHECKER_H
#define SPELLER_STDUNORDEREDSETCHECKER_H


class StdUnorderedSetChecker : public Checker {
public:
    StdUnorderedSetChecker();
    ~StdUnorderedSetChecker() final;
    bool check(const std::string &) final;
    void loadDictionary() final;

private:
    std::unordered_set<std::string> *dictionary;
};


#endif //SPELLER_STDUNORDEREDSETCHECKER_H
