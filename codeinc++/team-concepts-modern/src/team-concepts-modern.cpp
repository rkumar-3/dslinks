// team-concepts-modern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Trie.h"
#include <iostream>
#include <vector>
#include <memory>
#include <set>

using namespace std;

struct MyNode {
    //char c[26];
    MyNode **dyn_arr;

    MyNode() : dyn_arr(new MyNode*[26]{}) {};

    size_t size_of() {
        size_t size_row = sizeof(*dyn_arr) * 26;
        size_t size_element = 0;
        int i = 0;
        for (MyNode *p = dyn_arr[0]; p != dyn_arr[26]; p = dyn_arr[++i]) {
            if (p != NULL) {
                size_element += p->size_of();
            }
        }

        size_t size_total = size_row + size_element;
        return size_total;
    }

    void emplace(int i, MyNode* p) {
        if (i > 0 && i < 26) {
            dyn_arr[i] = p;
        }
    }

    void pointless() {
        cout << "hihi" << endl;
    }
};

typedef shared_ptr<MyNode> MySimpleNode;

struct MyNode2;

typedef shared_ptr<MyNode2> MySmartNode;

struct MyNode2 {
    vector<MySmartNode> english_alphabet;

    MyNode2() : english_alphabet(26, nullptr) {};

    // disabling copy constructors and defaulting ot move semantics
private:
    MyNode2(const MyNode2&) {};
    MyNode2& operator=(const MyNode2&) {};

public:
    size_t size_of() {

        size_t size_vector = sizeof(vector<MySmartNode>);
        //size_t size_row = english_alphabet.size() + size_vector;
        size_t size_element = 0;
        int i = 0;
        for (MySmartNode node : english_alphabet) {
            if (node != NULL) {
                size_element += node->size_of();
            }
        }

        size_t size_total = size_vector + size_element;
        return size_total;
    }

    void emplace(int i, MySmartNode node) {
        if (i > 0 && i < 26) {
            english_alphabet[i] = node;
        }
    }

    void pointless() {
        cout << "hihi" << endl;
    }
};

int main()
{
       
    shared_ptr<Trie> trie = make_shared<Trie>();

    /**
     * 1. Build a DB of game titles
     */
    trie->insert("dslink-game-ping-pong");
    trie->insert("dslink-poker");


    /**
     * 2. Trie allows fast search.
     * 
     *
     * Search cost = O(M) where M is the length of the search key.
     *  faster than a balanced Binary Search Tree.
     */
    

    /**
     * 3. Unit Testing 
     * - simple without mock frameworks
     */

    // Positive case
    bool findMyGame = trie->search("dslink-game-ping-pong");
    cout << "dslink-game title 1" 
         <<  (findMyGame ? " Found" : "Not Available") << endl;

    // Negative case
    findMyGame = trie->search("dslink-play-game-pokiman");
    cout << "dslink-game title 2"
        << (findMyGame ? " Found" : " Not Available") << endl;


    /**
    * 4. Unit Testing
    * - Uses google mock Test framework
    */

    // See "testm-concepts-test" project lisitng  
    // It sets up a Test Suite and run them!



    // do this here - so the memory leak checker is happy!
    trie.reset();
   

    _CrtDumpMemoryLeaks();

    return 0;
}
