#pragma once

#include "TrieNode.h"

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    virtual ~Trie();

public:
    void insert(const string& word);
    bool search(const string& word);

private:
    void insert(TrieNode* node, const string& word, int posIndex);
    void release_resources();

    TrieNode* add_character(TrieNode* node, const char c);
    TrieNode* find_character(TrieNode* node, const char c);
    bool atWordEnd(const string& word, int posIndex);
    bool atWordEOF(const string& word, int posIndex);

    bool validate(const char c);
    int  toIndex(char c);
};
