#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H
namespace jwwang {
class TestArray
{
private:
    /* data */
public:
    void RunTest() const;
    void TestPop() const;
    void TestPush() const;
    void TestGetValueAt() const;
    void TestCapacity() const;
    void TestInsert() const;
    void TestPrepend() const;
    void TestDelete() const;
    void TestRemove() const;
    void TestFind() const;
    void TestDebugString() const;
};
}
#endif //TEST_ARRAY_H