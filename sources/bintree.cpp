#include <string>
#include "../headers/bintree.h"

node *BinTree::insert(node *currentNode, const std::string &word) {
    if (root == nullptr) {
            root = new node();
            root->value = word;
            return root;
    }
    if (currentNode == nullptr) {
        currentNode = new node();
        currentNode->value = word;
        return currentNode;
    }

    if (word < currentNode->value) {
        currentNode->left = insert(currentNode->left, word);
    }
    else if (word > currentNode->value) {
        currentNode->right = insert(currentNode->right, word);
    }
    return currentNode;
}

node *BinTree::find(node *currentNode, const std::string &word) {
    if (currentNode == nullptr || currentNode->value == word) {
        return currentNode;
    }
    if (currentNode->value > word) {
        return find(currentNode->left, word);
    }
    return find(currentNode->right, word);
}
