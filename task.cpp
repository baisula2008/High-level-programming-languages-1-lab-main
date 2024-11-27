#include "std_lib_facilities.h"

class Complex {
public:
    Complex() {}
    Complex(double r, double i);

    double modulus();

    double get_re()
    {
        return re;
    }

    double get_im()
    {
        return im;
    }

private:
    double re;
    double im;
};

Complex::Complex(double r, double i) : re(r), im(i) {}

double Complex::modulus()
{
    return sqrt(re * re + im * im);
}

ostream& operator<<(ostream& os, Complex& c)
{
    if (c.get_im() < 0)
    {
        return os << c.get_re() << c.get_im() << "i";
    }
    else if (c.get_im() > 0)
    {
        return os << c.get_re() << "+" << c.get_im() << "i";
    }
    else
    {
        return os << c.get_re();
    }
}

Complex operator+(Complex& c1, Complex& c2)
{
    double r = 0.0, i = 0.0;
    r = c1.get_re() + c2.get_re();
    i = c1.get_im() + c2.get_im();
    return Complex(r, i);
}

int main()
{
    Complex c1(3, 4);
    cout << c1 << endl;
    cout << "Modulus of c1: " << c1.modulus() << endl;

    cout << "--------" << endl;

    Complex c2(2, -2);
    cout << c2 << endl;
    cout << "Modulus of c2: " << c2.modulus() << endl;

    cout << "--------" << endl;

    Complex c3 = c1 + c2;
    cout << c3 << endl;
    cout << "Modulus of c3: " << c3.modulus() << endl;
    return 0;
}