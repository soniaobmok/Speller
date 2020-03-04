#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H


class Checker {
public:
    virtual ~Checker() = default;
    virtual void loadDictionary() = 0;
    virtual void loadText(const std::string &);
    virtual void loadAllTexts();

    virtual bool check(const std::string &) = 0;

    std::string getMethodName();
    void setMethodName(const std::string &);

    int getCheckedWords();
    int getWrongWords();

    static std::string getWord(const std::string&);

private:
    std::string methodName;
    int checkedWordsNumber = 0;
    int wrongWordsNumber = 0;
};

#endif //SPELLER_CHECKER_H
