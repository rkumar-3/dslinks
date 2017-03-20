#pragma once

#include "Consts.h"
#include <iostream>
#include <string>

using namespace std;

typedef pair<string, string> Word;

struct TrieNode {
    TrieNode **alphabetNodes;
    bool wordEnd;

    TrieNode() : wordEnd(false) {
        alphabetNodes = allocate_resource();
    }

    virtual ~TrieNode() {
        release_resource();
    }

    void markWordEnd() {
        wordEnd = true;
    }

    bool isWordEnd() {
        return wordEnd;
    }

private:
    // allocate an array to represent the english alphabet
    TrieNode** allocate_resource() {
        TrieNode **nodeArray = new TrieNode*[const_sizeof_english_alphabet] {};
    }

    // release the array
    void release_resource() {
        delete [] alphabetNodes;
    }
};


class Trie {
    private:
        TrieNode* root;

    public:
        Trie() : root(NULL) {};
        virtual ~Trie() {};

    public:
        /*
        void insert(const string& word) {
            TrieNode *current = root;
           
            for (int i = 0; i < word.length; i++) {

                char c = word.at(i);

                if (validAlphabet(c)) {
                    traverse
                }
            }

        }
        */
        void insert(const string& word) {
 
            // create a root node
            if (root == NULL) {
                root = new TrieNode();
            }

            // traverse trie to insert every character in the word. 
            insert(root, word, 0);
        }

        bool search(const string& word) {
            if (root == NULL) {
                return false;
            }

            int pos = 0;
            TrieNode *current = root;
            while (current) {
                const char c = word.at(pos);
         
                // skip chars not in english alphabet.
                if (!validate(c)) {
                    pos++;
                    continue;
                }

                TrieNode *nextNode = findCharacterNode(current, c);
                if (nextNode->isWordEnd()) {
                    return true;
                }

                // traverse to the next character in the word
                pos++;
                current = nextNode;
            }

            return false;
        }

        void insert(TrieNode* node, const string& word, int posIndex) {

            if (atWordEOF(word, posIndex)) {
                return;
            }

            const char c = word[posIndex];
            if (!validate(c)) {
                // ignore chars not in english alphabet and skip to next.
                insert(node, word, posIndex++);
                return;
            }

            // add character to trie DS
            TrieNode* nextNode = getCharacterNode(node, c);                
            if (atWordEnd(word, posIndex)) {
                // mark the last character.
                nextNode->markWordEnd();
            }
            else {
                // traverse to next character in the word
                insert(nextNode, word, posIndex++);
            }

            return;
        }

    private:

        TrieNode* findCharacterNode(TrieNode* node, const char c) {
            int alphabetPos = toIndex(c);

            TrieNode* findAlphabet = node->alphabetNodes[alphabetPos];
            return findAlphabet;
        }

        TrieNode* getCharacterNode(TrieNode* node, const char c) {
            int alphabetPos = toIndex(c);

            TrieNode* findAlphabet = node->alphabetNodes[alphabetPos];
            // No representation found for this alphabet 
            if (findAlphabet == NULL) {

                // make and add one to the Current TrieNode.
                findAlphabet = new TrieNode();
                node->alphabetNodes[alphabetPos] = findAlphabet;
            }

            return findAlphabet;
        }

        // at last valid character in the word
        bool atWordEnd(const string& word, int posIndex) {
            return (posIndex >= word.length);
        }

        // posIndex beyond last valid character
        bool atWordEOF(const string& word, int posIndex) {
            return (posIndex >= word.length);
        }

        // checks char to be an english alphabet ('a'...'z')
        bool validate(const char c) {

            // lowercase 'a' ... 'z'
            if (c >= 'a' && c <= 'z') {
                return true;
            }
            else if (c >= 'A' && c <= 'Z') {
                return true;
            }
            
            return false;
        }

        int toIndex(char c) {
            // lowercase 'a' ... 'z'
            if (c >= 'a' && c <= 'z') {
                return (c - 'a');
            }
            else if (c >= 'A' && c <= 'Z') {
                return (c - 'A');
            }
        }
};
