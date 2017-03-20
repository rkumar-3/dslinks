// team-concepts-test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <gtest\gtest.h>
#include <ForTests\Isolator.h>
#include "Trie.h"

class TestSuite_Trie : public ::testing::Test {

public:
    TestSuite_Trie() {
        // initialization code here
    }
    ~TestSuite_Trie() {
        // cleanup any pending stuff, but no exceptions allowed
    }

    void SetUp() {
        // code here will execute just before the test ensues 
    }

    void TearDown() {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
        ISOLATOR_CLEANUP();

    }

    // put in any custom data members that you need 
private:
    //Trie98 trie;
};

TEST_F(TestSuite_Trie, TestMemoryUsage)
{
    Trie* trie = new Trie();
    delete trie;
    cout << "test" << endl;
}



TEST_F(TestSuite_Trie, SuccessfulInsertIntoDS)
{
    Trie trie;

    // setup a pre condition
    string name = "ravi";
    trie.insert(name);

    EXPECT_EQ(true, trie.search(name));
}

TEST_F(TestSuite_Trie, UnSuccessfulInsertIntoDS)
{
    Trie trie;

    // search for a non-existant string
    string name = "ravi";

    EXPECT_EQ(true, trie.search(name));
    cout << endl;
}


TEST_F(TestSuite_Trie, MemoryUsageTestForDS)
{
    Trie* trie = new Trie();

    // setup a pre condition
    string name = "ravi";
    trie->insert(name);

    EXPECT_EQ(true, trie->search(name));
    delete trie;
}


int main(int argc, _TCHAR* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
    return 0;
}
