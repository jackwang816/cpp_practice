#include<iostream>
#include<vector>
#include <assert.h>
#include "vectorTest.h"
namespace jwwang
{
    void TestVector::RunTest() const
    {
        TestConstruct();
        TestElemModify();
        TestAccess();
        TestCapacity();
        TestIterators();
    }

    void TestVector::TestConstruct() const
    {
        // constructors used in the same order as described above:
        std::vector<int> first;                                // empty vector of ints
        std::vector<int> second (4,100);                       // four ints with value 100
        std::vector<int> third (second.begin(),second.end());  // iterating through second
        std::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are:";
        for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';

        return;
    }

    void TestVector::TestAccess() const
    {
        std::vector<unsigned> myvector;
        myvector.push_back(78);
        myvector.push_back(16);

        assert(myvector.front() == 78);
        assert(myvector.back() == 16);
        // now front equals 78, and back 16

        myvector.front() -= myvector.back();
        assert(myvector.front() == 62);
        std::cout << "front: " << myvector.front() << ",back: " << myvector.back() << '\n';

        std::vector<unsigned> testvector(10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<testvector.size(); i++)
            testvector.at(i)=i;

        for (unsigned i=0; i<testvector.size(); i++) {
            assert(testvector.at(i) == i);
            assert(testvector[i] == i);
        }
        unsigned* p = testvector.data();
        for (unsigned i=0; i<testvector.size(); i++) {
            assert(p[i] == i);
        }
        return;
    }

    void TestVector::TestCapacity() const
    {
        return;
    }

    void TestVector::TestElemModify() const
    {
        return;
    }

    void TestVector::TestIterators() const
    {
        return;
    }

} // namespace jwwang


