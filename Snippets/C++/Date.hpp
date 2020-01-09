#ifndef DATE_H_
#define DATE_H_

#include <string>
using namespace std;

class Date {
  private:
    int _year;
    int _month;
    int _day;
    void standardize() {
        // TODO
    }

  public:
    Date(const int year = 1970, const int month = 1, const int day = 1) {
        _year = year;
        _month = month;
        _day = day;
        standardize();
    }

    Date(const string &s) {
        // TODO
    }

    Date(const Date &d) {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    void add_year(const int y) {
        _year += y;
        standardize();
    }

    void add_month(const int m) {
        _month += m;
        standardize();
    }

    void add_day(const int d) {
        _day += d;
        standardize();
    }

    inline bool is_leap_year() {
        return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
    }

    string to_string() {
        // TODO
    }

    Date operator+(const int day) { return Date(_year, _month, _day + day); }

    Date &operator+=(const int day) {
        *this = *this + day;
        return *this;
    }

    Date operator-(const int day) { return Date(_year, _month, _day - day); }

    Date &operator-=(const int day) {
        *this = *this - day;
        return *this;
    }

    Date &operator++() {
        *this = *this + 1;
        return *this;
    }

    Date operator++(int) {
        Date t = *this;
        *this = *this + 1;
        return t;
    }

    Date &operator--() {
        *this = *this - 1;
        return *this;
    }

    Date operator--(int) {
        Date t = *this;
        *this = *this - 1;
        return *this;
    }
};

#endif