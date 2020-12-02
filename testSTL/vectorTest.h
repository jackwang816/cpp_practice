#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H
namespace jwwang {
class TestVector
{
private:
    /* data */
public:
    void RunTest() const;
    void TestConstruct() const;
    void TestElemModify() const;
    void TestAccess() const;
    void TestCapacity() const;
    void TestIterators() const;
};
}
#endif //TEST_ARRAY_H
