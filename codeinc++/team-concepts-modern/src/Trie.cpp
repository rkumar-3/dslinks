#include "Trie.h"
#include <memory>

using namespace std;


Trie::Trie(): root(nullptr) 
{
};

Trie::~Trie() 
{
    //release_resources();
};

void Trie::insert(const string& word) 
{

    // create a root node
    if (root == NULL) {
        //root = new TrieNode();
        root = make_shared<TrieNode>();
    }

    // traverse trie to insert every character in the word. 
    insert(root.get(), word, 0);
}

bool Trie::search(const string& word) 
{
    if (root == NULL) {
        return false;
    }

    /** 
     * searches for the given word in the trie in O(M)
     * where M is the length of the Word. 
     *
     */

    int pos = 0;
    TrieNode *current = root.get();
    while (current) {
        const char c = word.at(pos);

        // skip chars not in english alphabet.
        if (!validate(c)) {
            pos++;
            continue;
        }

        TrieNode *nextNode = find_character(current, c);
        if (nextNode) {
            if (nextNode->isEndOfWord()) {
                return true;
            }
        }

        // traverse to the next character in the word
        pos++;
        current = nextNode;
    }

    return false;
}

//----------------------- Private Helpers ----------------------------

void Trie::insert(TrieNode* node, const string& word, int posIndex) 
{
    if (atWordEOF(word, posIndex)) {
        return;
    }

    const char c = word[posIndex];
    if (!validate(c)) {
        // ignore chars not in english alphabet and skip to next.
        insert(node, word, ++posIndex);
        return;
    }

    // adds the character to trie DS and returns the node representing the alphabet
    TrieNode* nextNode = add_character(node, c);
    if (atWordEnd(word, posIndex)) {
        // mark the last character.
        nextNode->markEndOfWord();
    }
    else {
        // traverse to next character in the word
        insert(nextNode, word, ++posIndex);
    }

    return;
}

void Trie::release_resources() 
{
    //if (root = NULL) {
        //return;
    //}

    //delete root;
    root.reset();
}


TrieNode* Trie::add_character(TrieNode* node, const char c) 
{
    // find char position in ascii table.
    int alphabetPos = toIndex(c);

    /** 
     * find and return the alphabet node at the position
     */
 
   // TrieNode* alphabetNode = node->at(alphabetPos);

    SmartNode aNode = node->at(alphabetPos);
    // No alphabet exists at pos
    if (aNode.get() == NULL) {

        // make and populate the alphabet at that index position.
        aNode = make_shared<TrieNode>();
        node->populate(alphabetPos, aNode);
    }

    return aNode.get();
}

TrieNode* Trie::find_character(TrieNode* current, const char c)
{
    int alphabetPos = toIndex(c);

    TrieNode* findAlphabet = current->english_alphabet[alphabetPos].get();
    return findAlphabet;
}

// at last valid character in the word
bool Trie::atWordEnd(const string& word, int posIndex) 
{
    return (posIndex == (int)word.length() - 1);
}

// posIndex beyond last valid character
bool Trie::atWordEOF(const string& word, int posIndex) 
{
    return (posIndex >= (int)word.length());
}

// checks char to be an english alphabet ('a'...'z')
bool Trie::validate(const char c) 
{
    // lowercase 'a' ... 'z'
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    else if (c >= 'A' && c <= 'Z') {
        return true;
    }

    return false;
}

int Trie::toIndex(char c) 
{
    // lowercase 'a' ... 'z'
    if (c >= 'a' && c <= 'z') {
        return (c - 'a');
    }
    else if (c >= 'A' && c <= 'Z') {
        return (c - 'A');
    }

    return -1;
}