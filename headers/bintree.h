#ifndef SPELLER_BINTREE_H
#define SPELLER_BINTREE_H

struct node {
    std::string value;
    node *left;
    node *right;
};

class BinTree {
public:
    node* insert(node *, const std::string &);
    static node* find(node *, const std::string &);

//private:
    node *root;
};


#endif //SPELLER_BINTREE_H
