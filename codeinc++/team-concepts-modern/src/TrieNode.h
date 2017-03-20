#pragma once
#include "TrieConsts.h"
#include <string>
#include <vector>
#include <memory>


using namespace std;

/**
* defines an easy to use smart pointer
*/
struct TrieNode; // forward declaration needed here.
typedef std::shared_ptr<TrieNode> SmartNode;


struct TrieNode {
    //TrieNode    **english_alphabet;

    // replaced with a stl container of Smart Pointer objects
    vector<SmartNode>   english_alphabet;
    bool        wordEnds;

    TrieNode();
    virtual ~TrieNode();

    SmartNode   at(const int index);
    void        emplace(int atIndex, SmartNode node);
    void        populate(const int index, SmartNode alphabetNode);
    void        markEndOfWord();
    bool        isEndOfWord();

private:
    TrieNode** allocate_resource();
    void       release_resource();
    void       release_childNodes();
    void       validate(int index);
};
