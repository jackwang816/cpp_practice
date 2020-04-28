#ifndef ARRAY_H
#define ARRAY_H
namespace jwwang
{
const int MIN_CAPACITY = 16;
const int GROWTH_FACTOR = 1;
const int SHRINK_FACTOR = 2;

class MyArray
{
public:
    MyArray();
    MyArray(const int* init, int len);
    MyArray(const MyArray& cp); //copy constructor
    MyArray& operator =(const MyArray& assign); // assignment operator

    ~MyArray(); // deconstructor

    // Returns the number of items stored in the vector.
    int GetSize() const;
    bool IsEmpty() const;
    // Returns the capacity of the vector.
    int GetCapacity() const;
    // Prints out public information about the vector.
    void DebugString() const;
    // Appends the given value to the end of the vector.
    void Push(int value);
    // Returns the value stored at the given index
    int GetValueAt(int index) const;
    // Returns the last item in the vector, and removes it.
    int Pop();
    // Inserts the given value at the given index, shifting
    // current and trailing items to the right.
    void Insert(int index, int value);
    // Prepends the given value to the vector, shifting trailing
    // items to the right.
    void Prepend(int value);
    // Deletes item at index, shifting all trailing elements left.
    void Delete(int index);
    // Removes all instances of value from the vector.
    void Remove(int value);
    // Looks for value and returns first index with that value, -1 if not found.
    int Find(int value) const;
    // Get max capacity
    inline int maxCap(int capa, int capb)
    {
        return capa > capb ? capa : capb;
    }
    inline int getNewCap(int newSize, int capacity)
    {
        int newCap = newSize > capacity ? capacity << GROWTH_FACTOR :
                     capacity >> GROWTH_FACTOR;
        return maxCap(newCap, MIN_CAPACITY);
    }

private:
    int *array;
    int capacity, size;
    inline void copy_array(int*src, const int*dst, int len) {
        for (int i=0; i<len; i++) {
            src[i] = dst[i];
        }
    }
    void ResizeMyArray();
    // Resize array when new size exceed capacity or less than lower limit
    inline void Resize(int newSize, int capacity)
    {
        if (newSize > capacity || newSize < capacity>>SHRINK_FACTOR) {
            ResizeMyArray();
        }
    }
};

} // namespace jwwang
#endif //ARRAY_H