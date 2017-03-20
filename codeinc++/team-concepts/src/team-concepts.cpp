// team-concepts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Trie.h"

using namespace std;

int main()
{

   Trie* trie = new Trie();
    
    trie->insert("ravi");

    delete trie;
    


    _CrtDumpMemoryLeaks();

    return 0;
}

