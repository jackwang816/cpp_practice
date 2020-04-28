#include "array.h"
#include <assert.h>
#include <iostream>

namespace jwwang {

MyArray::MyArray():size(0), capacity(MIN_CAPACITY)
{
    array = new int[capacity];
    assert(array);
}

MyArray::MyArray(const int* init, int len): size(len)
{
    assert(init);
    capacity = getNewCap(size, MIN_CAPACITY);
    array = new int[capacity];
    assert(array);
    copy_array(array, init, len);
}

MyArray::MyArray(const MyArray& cp):size(cp.size), capacity(cp.capacity)
{
    array = new int[capacity];
    assert(array);
    copy_array(array, cp.array, cp.size);
}

MyArray& MyArray::operator=(const MyArray& assign)
{
    if (this == &assign)
        return *this;
    delete [] array;
    size = assign.size;
    capacity = assign.capacity;
    array = new int[capacity];
    assert(array);
    copy_array(array, assign.array, assign.size);
    return *this;
}

int MyArray::GetSize() const
{
    return size;
}

int MyArray::GetCapacity() const
{
    return capacity;
}

bool MyArray::IsEmpty() const
{
    return size==0;
}

void MyArray::DebugString() const
{
    std::cout << "size=" << size
            << ", capacity=" << capacity
            << ", items:" << std::endl;

    for (int i = 0; i < size; ++i) {
        printf(" | %d: %d", i, array[i]);
    }
    std::cout << " |" << std::endl;
}

void MyArray::Push(int value)
{
    Resize(++size, capacity);
    array[size-1] = value;
}

int MyArray::GetValueAt(int index) const
{
    assert(index < size);
    return array[index];
}

int MyArray::Pop()
{
    assert(size > 0);
    int ret = array[--size];
    Resize(size, capacity);
    return ret;
}

void MyArray::Insert(int index, int value)
{
    assert(index < size && index >= 0);
    Resize(++size, capacity);
    for (int i=size-1; i>index; i--) {
        array[i] = array[i-1];
    }
    array[index] = value;
}

void MyArray::Prepend(int value)
{
    Insert(0, value);
}

void MyArray::Delete(int index)
{
    assert(index < size && index >= 0);
    for (int i=index; i<size-1; i++) {
        array[i] = array[i+1];
    }
    Resize(--size, capacity);
}

void MyArray::Remove(int value)
{
    for (int i=size-1; i>=0; i--) {
        if (value == array[i])
            Delete(i);
    }
}

int MyArray::Find(int value) const
{
    for (int i=0; i<size; i++) {
        if (array[i] == value)
            return i;
    }
    return -1;
}

// private funcion
void MyArray::ResizeMyArray()
{
    int * new_array;
    int newCap = getNewCap(size, capacity);
    if (size < capacity>>SHRINK_FACTOR && capacity <= newCap)
        return;
    capacity = newCap;
    new_array = new int[capacity];
    assert(new_array);
    copy_array(new_array, array, size);
    delete [] array;
    array = new_array;
}

MyArray::~MyArray()
{
    if (array)
        delete [] array;
}

} // namespace jwwang


