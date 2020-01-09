#include "Fraction.h"

Fraction::Fraction(const int num, const int den)
    :m_num(num), m_den(den){
    normalize();
}

Fraction::Fraction(double n){
    m_den = 1;
    while (n - (int)n != 0){
        n *= 10;
        m_den *= 10;
    }
    m_num = n;
    normalize();
}

Fraction::Fraction(const string &s) throw(exception){
    // 计数器
    unsigned i;

    // 字符串合法性检查及'/'位置确定
    int m = -1;
    for (i = 0; i < s.length(); i++)
        if ('/' == s[i])
            m = i;

    // 没有分子
    if (0 == m){
        m_num = 0;
        m_den = 1;
        return;
    }

    // 没有分母
    if (m == s.length())
        throw invalid_argument("No den");

    // 没有'/'
    if (-1 == m){
        *this = atof(s.c_str());
        return;
    }

    // 分离分子分母
    string num = s.substr(0, m);
    m_num = atoi(num.c_str());
    string den = s.substr(m + 1, s.length());
    if (0 == (m_den = atoi(den.c_str())))
        throw invalid_argument("den is 0");
    normalize();
}

Fraction::Fraction(const char* s){
    string str(s);
    *this = str;
}

Fraction::Fraction(const Fraction &f){
    this->m_num = f.m_num;
    this->m_den = f.m_den;
}

void Fraction::normalize() throw(int){
    if (0 == m_den)
        throw -1;
    if (m_den < 0){
        m_num = -m_num;
        m_den = -m_den;
    }
    int g = gcd();
    m_num /= g;
    m_den /= g;
}

int Fraction::gcd(){
    if (m_num == 0)
        return 1;
    int n, d, t;
    n = abs(m_num);
    d = abs(m_den);
    t = d%n;
    while (t){
        d = n;
        n = t;
        t = d%n;
    }
    return n;
}

Fraction Fraction::operator+(const Fraction &f) const{
    return Fraction(this->m_num * f.m_den + f.m_num * this->m_den,\
                    this->m_den * f.m_den);
}

Fraction Fraction::operator+=(const Fraction &f){
    *this = *this + f;
    return *this;
}

Fraction Fraction::operator-(const Fraction &f) const{
    return Fraction(this->m_num * f.m_den - f.m_num * this->m_den,\
                    this->m_den * f.m_den);
}

Fraction Fraction::operator-=(const Fraction &f){
    *this = *this - f;
    return *this - f;
}

Fraction Fraction::operator*(const Fraction &f) const{
    return Fraction(this->m_num * f.m_num,\
                    this->m_den * f.m_den);
}

Fraction Fraction::operator*=(const Fraction &f){
    *this = *this * f;
    return *this;
}

Fraction Fraction::operator/(const Fraction &f) const{
    return Fraction(this->m_num * f.m_den,\
                    this->m_den * f.m_num);
}

Fraction Fraction::operator/=(const Fraction &f){
    *this = *this / f;
    return *this;
}

Fraction& Fraction::operator++(){
    this->m_num += this->m_den;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction t = *this;
    ++*this;
    return t;
}

Fraction& Fraction::operator--(){
    this->m_num -= this->m_den;
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction t = *this;
    --(*this);
    return t;
}

bool Fraction::operator==(const Fraction &f){
    return (this->m_num == f.m_num && this->m_den == f.m_den);
}

bool Fraction::operator!=(const Fraction &f){
    return !(*this == f);
}

bool Fraction::operator>(const Fraction &f){
    return (m_num *f.m_den - f.m_num * m_den) > 0;
}

bool Fraction::operator>=(const Fraction &f){
    return (*this > f || *this == f);
}

bool Fraction::operator<(const Fraction &f){
    return (m_num *f.m_den - f.m_num * m_den) > 0;
}

bool Fraction::operator<=(const Fraction &f){
    return (*this < f || *this == f);
}

Fraction& Fraction::operator=(const Fraction &f){
    this->m_num = f.m_num;
    this->m_den = f.m_den;
    return *this;
}

ostream& operator<<(ostream &os, const Fraction &f){
    if (0 == abs(f.m_num) % f.m_den)
        os << f.m_num / f.m_den;
    else
        os << f.m_num << "/" << f.m_den;
    return os;
}

istream& operator>>(istream &is, Fraction &f){
    string str;
    is >> str;
    f = Fraction(str);
    return is;
}

Fraction::operator int() const{
    return m_num / m_den;
}

Fraction::operator float() const{
    return (float)m_num / m_den;
}

Fraction::operator double() const{
    return (double)m_num / m_den;
}

int main() {
    Fraction f1(1,2), f2(3,2);
    cout<<"\t\tf1\tf2"<<endl;
    cout<<"\t\t"<<f1<<"\t"<<f2<<endl;
    cout<<"f1++\t\t"<<f1++<<"\t"<<f2<<endl;
    cout<<"++f2\t\t"<<f1<<"\t"<<++f2<<endl;
    cout<<"f1--\t\t"<<f1--<<"\t"<<f2<<endl;
    cout<<"--f2\t\t"<<f1<<"\t"<<--f2<<endl;
    cout<<"++(++f1)\t"<<++(++f1)<<"\t"<<f2<<endl;

    return 0;
}

