#pragma once
#include "TrieConsts.h"
#include <string>

using namespace std;

struct TrieNode {
    TrieNode    **english_alphabet;
    bool        wordEnds;

    TrieNode();
    virtual ~TrieNode();

    TrieNode*   at(const int index);
    void        populate(const int index, TrieNode* alphabetNode);
    void        markEndOfWord();
    bool        isEndOfWord();

private:
    TrieNode** allocate_resource();
    void       release_resource();
    void       release_childNodes();
    void       validate(int index);
};
