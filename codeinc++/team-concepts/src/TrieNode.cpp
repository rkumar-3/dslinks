#include "TrieNode.h"

using namespace std;

TrieNode::TrieNode() : wordEnds(false) {
   english_alphabet = allocate_resource();
}

TrieNode::~TrieNode() {
   release_resource();
}

TrieNode* TrieNode::at(const int index) {
    validate(index);

    return  english_alphabet[index];
}

void TrieNode::populate(const int index, TrieNode* alphabetNode) {
    validate(index);

    english_alphabet[index] = alphabetNode;
}

void TrieNode::markEndOfWord() {
    wordEnds = true;
}

bool TrieNode::isEndOfWord() {
    return wordEnds;
}

TrieNode** TrieNode::allocate_resource() {
    TrieNode **nodeArray = new TrieNode*[const_sizeof_english_alphabet] {};
    return nodeArray;
}

// release the array
void TrieNode::release_resource() {

    release_childNodes();
    delete[] english_alphabet;
}

void TrieNode::release_childNodes() {
    for (int i = 0; i < const_sizeof_english_alphabet; i++) {

        if (english_alphabet[i] != NULL) {
            delete english_alphabet[i];
            english_alphabet[i] = NULL;
        }
    }
}

void TrieNode::validate(int index) {
    if (index >= const_sizeof_english_alphabet) {
        throw std::invalid_argument("index to array past the eof");
    }
}