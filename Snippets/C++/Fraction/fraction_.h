#pragma once

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class fraction {
  public:
    /*
     * 构造函数
     */

    fraction() : m_num(0), m_den(1) {}

    fraction(const int num, const int den) : m_num(num), m_den(den) {
        normalize();
    }

    fraction(const int n) : m_num(n), m_den(1) {}

    fraction(const double n);

    fraction(const string f) {
        // 计数器
        unsigned int i;
        // 判断'/'位置
        unsigned int m;
        for (m = 0; m < f.length(); m++) {
            if ('/' == f[m]) {
                break;
            }
        }
        if (0 == m || f.length() == m) {
            exit(EXIT_FAILURE);
        }
        // 判断两部分字符（含分子分母符号判断）是否符合要求
        for (i = 1; i < m; i++) {
            if (f[i] < '0' || f[i] > '9') {
                exit(EXIT_FAILURE);
            }
        }
        for (i = m + 2; i < f.length(); i++) {
            if (f[i] < '0' || f[i] > '9') {
                exit(EXIT_FAILURE);
            }
        }
        if ('-' != f[0] && (f[0] < '0' || f[0] > '9')) {
            exit(EXIT_FAILURE);
        }
        if ('-' != f[m + 1] && (f[m + 1] < '0' || f[m + 1] > '9')) {
            exit(EXIT_FAILURE);
        }
        // 分离分子分母，判断两部分正负
        unsigned int l;
        m_num = m_den = 0; // 不能对已有分数进行直接赋值
        for (l = m - 1, i = 0; l >= 0 && i < m; l--, i++) {
            if ('-' == f[l]) {
                m_num = -m_num;
            } else {
                m_num += (f[l] - '0') * pow(10, i);
            }
        }
        for (l = f.length() - 1, i = 0; l > m && i < f.length() - m; l--, i++) {

            if ('-' == f[l]) {
                m_den = -m_den;
            } else {
                m_den += (f[l] - '0') * pow(10, i);
            }
        }
        //分数化简
        normalize();
    }

    /*
     * 基本运算
     */

    // 加法
    template <typename TYPE> fraction operator+(const TYPE &f) {
        return fraction(num * fraction(f).den + fraction(f).num * den,
                        den * fraction(f).den);
    }

    template <typename TYPE> void operator+=(const TYPE &f) {
        *this = *this + fraction(f);
    }

    // 减法
    template <typename TYPE> fraction operator-(const TYPE &f) {
        return fraction(num * fraction(f).den - fraction(f).num * den,
                        den * fraction(f).den);
    }

    template <typename TYPE> void operator-=(const TYPE &f) {
        *this = *this - fraction(f);
    }

    // 乘法
    template <typename TYPE> fraction operator*(const TYPE &f) {
        return fraction(num * fraction(f).num, den * fraction(f).den);
    }

    template <typename TYPE> void operator*=(const TYPE &f) {
        *this = *this * fraction(f);
    }

    // 除法
    template <typename TYPE> fraction operator/(const TYPE &f) {
        return fraction(num * fraction(f).den, den * fraction(f).num);
    }

    template <typename TYPE> void operator/=(const TYPE &f) {
        *this = *this / fraction(f);
    }

    // 取负
    fraction operator-() { return fraction(-m_num, m_den); }

    // 前置++
    fraction operator++() { return fraction(m_num + m_den, m_den); }

    // 后置++
    fraction operator++(int) {
        fraction temp;
        temp = *this;
        ++*this;
        return temp;
    }

    // 前置--
    fraction operator--() { return fraction(m_num - m_den, m_den); }

    // 后置--
    fraction operator--(int) {
        fraction temp;
        temp = *this;
        --*this;
        return temp;
    }

    /* 逻辑关系 */

    // 相等
    template <typename TYPE> bool operator==(const TYPE &f) {
        return num * fraction(f).den == fraction(f).num * den;
    }

    // 不相等
    template <typename TYPE> bool operator!=(const TYPE &f) {
        return !(num * fraction(f).den == fraction(f).num * den);
    }

    // 大于
    template <typename TYPE> bool operator>(const TYPE &f) {
        return (num * fraction(f).den - fraction(f).num * den) > 0;
    }

    // 小于
    template <typename TYPE> bool operator<(const TYPE &f) {
        return (m_num * fraction(f).m_den - fraction(f).m_num * m_den) < 0;
    }

    /* 输入输出 */

    // 赋值
    template <typename TYPE> void operator=(const TYPE &f) {
        m_num = fraction(f).m_num;
        m_den = fraction(f).m_den;
    }

    // 输入
    friend istream &operator>>(istream &is, fraction &f) {
        is >> f.m_num;
        while (getchar() != '/')
            ;
        is >> f.m_den;
        f.normalize();
        return is;
    }

    // 输出
    friend ostream &operator<<(ostream &os, const fraction &f) {
        if (0 == f.m_num % f.m_den)
            os << f.m_num / f.m_den;
        else
            os << f.m_num << '/' << f.m_den;
        return os;
    }

  private:
    int m_num; // numerator
    int m_den; // denominator

    // 分数化简与分母是否为0判断
    void normalize() {
        // 判断分母是否为0
        if (0 == m_den) {
            exit(EXIT_FAILURE);
        }
        // 负分数化简为正分数
        if (m_den < 0) {
            m_num = -m_num;
            m_den = -m_den;
        }
        int g = gcd(); // 最大公约数
        m_num = m_num / g;
        m_den = m_den / g;
    }

    // 最大公约数
    int gcd() {
        if (m_num == 0) {
            return 1;
        }
        int n, d, t;
        n = abs(m_num);
        d = abs(m_den);
        t = d % n;
        while (t) {
            d = n;
            n = t;
            t = d % n;
        }
        return n;
    }
};