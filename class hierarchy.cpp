#include <iostream>

using namespace std;

class B
{
    int a;
public:
    B(int x)
    {
        a = x;
    }
    void showB()
    {
        cout << "B = " << a << '\n';
    }
};

class D1 : public B
{
    int b;
public:
    D1 (int x, int y) : B(y)
    {
        b = x;
    }
    void showD1()
    {
        cout << "D1 = " << b << '\n';
        showB();
    }
};

class D2 : private B
{
    int c;
public:
    D2 (int x, int y) : B(y)
    {
        c = x;
    }
    void showD2()
    {
        cout << "D2 = " << c << '\n';
        showB();
    }
};

class D3 : private B
{
    int d;
public:
    D3 (int x, int y) : B(y)
    {
        d = x;
    }
    void showD3()
    {
        cout << "D3 = " << d << '\n';
        showB();
    }
};

class D4 : private D1
{
    int e;
public:
    D4 (int x, int y, int z) : D1(y, z)
    {
        e = x;
    }
    void showD4()
    {
        cout << "D4 = " << e << '\n';
        showD1();
    }
};

class D5 : public D2, private D3
{
    int f;
public:
    D5(int x, int y, int z, int i, int j) : D2(y, z), D3(i, j)
    {
        f = x;
    }
    void showD5()
    {
        cout << "D5 = " << f << '\n';
        showD2();
        showD3();
    }
};

int main()
{
    setlocale (LC_ALL, "rus");
    D4 temp(20, 30, 40);
    D5 temp1(15, 20, 25, 30, 35);
    cout << "Классы иерархии D3:" << '\n';
    temp.showD4();
    cout << '\n';
    cout << "Классы иерархии D4:" << '\n';
    temp1.showD5();
}
