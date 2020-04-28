#include "array.h"
#include "test_array.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>

const int temp_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
namespace jwwang{

void TestArray::RunTest() const
{
    TestDebugString();
    TestPop();
    TestPush();
    TestGetValueAt();
    TestCapacity();
    TestInsert();
    TestPrepend();
    TestDelete();
    TestRemove();
    TestFind();
}

void TestArray::TestDebugString() const
{
    MyArray emptyArray, testArray{temp_array, 10};
    std::cout << "emptyArray:\n";
    emptyArray.DebugString();
    std::cout << "testArray:\n";
    testArray.DebugString();
}

void TestArray::TestPop() const
{
    MyArray emptyArray, testArray{temp_array, 10};
    emptyArray.Push(3);
    assert(emptyArray.GetSize()==1);
    assert(emptyArray.Pop()==3);
    for (int i=0, len=testArray.GetSize(); i<len; i++) {
        assert(testArray.Pop() == temp_array[len-i-1]);
        assert(testArray.GetSize() == len-i-1);
    }
    assert(emptyArray.IsEmpty());
    assert(testArray.IsEmpty());
}

void TestArray::TestPush() const
{
    MyArray emptyArray;
    emptyArray.Push(3);
    assert(emptyArray.GetSize()==1);
    emptyArray.Push(2);
    assert(emptyArray.GetSize()==2);
    emptyArray.Push(1);
    assert(emptyArray.GetSize()==3);
}
void TestArray::TestGetValueAt() const
{
    MyArray emptyArray;
    emptyArray.Push(3);
    emptyArray.Push(2);
    emptyArray.Push(1);
    assert(emptyArray.GetValueAt(0) == 3);
    assert(emptyArray.GetValueAt(1) == 2);
    assert(emptyArray.GetValueAt(2) == 1);
}

void TestArray::TestCapacity() const
{
    MyArray testArray;
    assert(testArray.GetCapacity()==MIN_CAPACITY);
    for (int i=0; i<17; i++) {
        testArray.Push(rand());
    }
    testArray.DebugString();
    assert(testArray.GetCapacity()==MIN_CAPACITY*2);
    for (int i=0; i<20; i++) {
        testArray.Push(rand());
    }
    assert(testArray.GetCapacity()==MIN_CAPACITY*4);
    for (int i=0;i<25;i++) {
        testArray.Pop();
    }
    assert(testArray.GetCapacity()==MIN_CAPACITY*2);
    for (int i=0;i<7;i++) {
        testArray.Pop();
    }
    assert(testArray.GetCapacity()==MIN_CAPACITY);
}

void TestArray::TestInsert() const
{
    MyArray TestArray{temp_array, 5};
    int tmp = TestArray.GetValueAt(0);
    
    TestArray.Insert(0, 5);
    assert(5==TestArray.GetValueAt(0) &&
            tmp==TestArray.GetValueAt(1) &&
            6==TestArray.GetSize());
    
    tmp = TestArray.GetValueAt(5);
    TestArray.Insert(5, 10);
    assert(10==TestArray.GetValueAt(5) &&
            tmp==TestArray.GetValueAt(6) &&
            7==TestArray.GetSize());
    
    tmp = TestArray.GetValueAt(6);
    TestArray.Insert(6,20);
    assert(20==TestArray.GetValueAt(6) &&
            tmp==TestArray.GetValueAt(7) &&
            8==TestArray.GetSize());
}

void TestArray::TestPrepend() const
{
    MyArray testArray(temp_array, 5);
    testArray.Prepend(10);
    assert(testArray.GetValueAt(0)==10 && testArray.GetSize()==6);
}

void TestArray::TestDelete() const
{
    MyArray testArray{temp_array, 10};
    testArray.Delete(0);
    assert(testArray.GetSize() == 9 && testArray.GetValueAt(0) == 2);
    testArray.Delete(8);
    assert(testArray.GetSize() == 8 && testArray.GetValueAt(7) == 9);
    testArray.Delete(5);
    assert(testArray.GetSize() == 7 && testArray.GetValueAt(5) == 8);
}

void TestArray::TestRemove() const
{
    MyArray testArray{temp_array, 5};
    int index;
    assert(testArray.GetSize() == 5);
    for (int i=0; i<5; i++) {
        index = rand() % testArray.GetSize();
        testArray.Insert(index, 20);
    }
    assert(testArray.GetSize() == 10);
    testArray.Remove(20);
    assert(testArray.GetSize() == 5);
}

void TestArray::TestFind() const
{
    MyArray testArray{temp_array, 10};
    assert(testArray.Find(1) == 0);
    assert(testArray.Find(0) == 9);
    testArray.Insert(2, 4);
    assert(testArray.Find(4) == 2);
    assert(testArray.Find(5) == 5);
}

}//namespace jwwang
int main(void)
{
    jwwang::MyArray defaultArray;
    int init[10] = {0};
    jwwang::MyArray initArray(init, 10);
    jwwang::MyArray cp{initArray};
    // // MyArray assign({10,1,2}, 3);
    jwwang::MyArray assign;
    assign = cp;
    assign = assign;
    // Test array
    jwwang::TestArray testArray;

    testArray.RunTest();
}