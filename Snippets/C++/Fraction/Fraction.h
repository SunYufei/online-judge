#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Fraction {
  private:
    int m_num;
    int m_den;
    void normalize() throw(int);
    int gcd();

  public:
    Fraction(const int num, const int den = 1);
    Fraction(double n);
    Fraction(const string &s) throw(exception);
    Fraction(const char *s);
    Fraction(const Fraction &f);

    Fraction operator+(const Fraction &f) const;
    Fraction operator+=(const Fraction &f);
    Fraction operator-() const;
    Fraction operator-(const Fraction &f) const;
    Fraction operator-=(const Fraction &f);
    Fraction operator*(const Fraction &f) const;
    Fraction operator*=(const Fraction &f);
    Fraction operator/(const Fraction &f1) const;
    Fraction operator/=(const Fraction &f);

    Fraction &operator++();
    Fraction operator++(int);
    Fraction &operator--();
    Fraction operator--(int);

    bool operator==(const Fraction &f);
    bool operator!=(const Fraction &f);
    bool operator>(const Fraction &f);
    bool operator>=(const Fraction &f);
    bool operator<(const Fraction &f);
    bool operator<=(const Fraction &f);

    Fraction &operator=(const Fraction &f);

    friend ostream &operator<<(ostream &os, const Fraction &f);
    friend istream &operator>>(istream &is, Fraction &f);

    operator int() const;
    operator float() const;
    operator double() const;
};
