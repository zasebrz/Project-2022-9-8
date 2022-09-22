#include<iostream>
#include<string>
using namespace std;

class  A
{
public:
    A(int a) :ma(a)
    {
        std::cout << "A" << std::endl;
    }
    ~A()
    {
        std::cout << "~A" << std::endl;
    }
public:
    int ma;
};
class B : public A
{
public:
    B(int b) :A(b), mb(b)
    {
        std::cout << "B" << std::endl;
    }
    ~B()
    {
        std::cout << "~B" << std::endl;
    }
public:
    int mb;
};
class CCCC : public A
{
public:
    CCCC(int c) :A(c), mc(c)
    {
        std::cout << "C" << std::endl;
    }
    ~CCCC()
    {
        std::cout << "~C" << std::endl;
    }
public:
    int mc;
};
class E
{
public:
    E(int e) :me(e)
    {
        std::cout << "E" << std::endl;
    }
    ~E()
    {
        std::cout << "~E" << std::endl;
    }
public:
    int me;
};
class DDDD :public B, virtual public E, public CCCC
{
public:
    DDDD(int d) :md(10), B(d), CCCC(d), E(d)
    {
        std::cout << "D" << std::endl;
    }
    ~DDDD()
    {
        std::cout << "~D" << std::endl;
    }
public:
    int md;
};

//int main()
//{
//    std::cout << "D size: " << sizeof(DDDD) << std::endl;
//
//    return 0;
//}