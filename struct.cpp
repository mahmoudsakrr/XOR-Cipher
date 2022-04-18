#include <iostream>
using namespace std;

class Rational
{
    private:
        int num, denom;
    public:
        Rational(int = 0, int = 1);
        void print();
        Rational add(Rational);
};

Rational::Rational(int n, int d)
{
    num = n;
    denom = d;
}

void Rational::print()
{
    cout << num << "/" << denom << endl;
}

Rational Rational::add(Rational r)
{
    Rational r3;
    r3.num = num + r.num;
    r3.denom = denom + r.denom;
    return r3;
}

int main()
{
    Rational x1(1,2);
    Rational x2(2,4);
    x1.print();
    x2.print();
    Rational x3(x1.add(x2));
    x3.print();
}