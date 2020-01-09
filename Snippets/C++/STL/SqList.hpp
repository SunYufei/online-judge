//
//	SqList.h
//	顺序线性表
//	存储下标从1开始，下标为0另有他用
//
//	2015-12-26
//
#ifndef SQLITE_H_
#define SQLITE_H_

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100
#define OVERFLOW -1
typedef int status;

template <typename T> class SqList {
  private:
    T *m_elem;
    int m_length; //有效元素数量
    int m_size;   //最大存储元素数
  public:
    SqList(const int size = MAXSIZE) : m_length(0), m_size(size) {
        m_elem = new T[size + 1];
        if (NULL == m_elem) {
            exit(OVERFLOW);
        }
    }

    SqList(const SqList<T> &from) {
        m_length = from.m_length;
        m_size = from.m_size;
        m_elem = new T[m_size + 1];
        if (NULL == m_elem) {
            exit(OVERFLOW);
        }
        for (int i = 1; i <= m_length; ++i) {
            m_elem[i] = from.m_elem[i];
        }
    }

    ~SqList() {
        delete[] m_elem;
        m_elem = NULL;
        m_length = 0;
        m_size = 0;
    }

    //线性表有效元素数量
    int length() { return m_length; }

    //线性表最大存储元素数
    int max_size() { return m_size; }

    //插入元素
    status insert(const int pos, const T data) {
        //位序错误
        if (pos < 1 || pos > m_length + 1) {
            return ERROR;
        }
        //存储空间已满
        if (m_length == m_size) {
            return ERROR;
        }
        // p指向插入位置
        T *p = &m_elem[pos];
        //插入位置向后移动数据
        for (T *q = &m_elem[m_length]; q >= p; --q) {
            *(q + 1) = *q;
        }
        *p = data;
        ++m_length;
        return OK;
    }

    //删除元素
    status delete_data(const int pos, T *data = NULL) {
        //位序错误
        if (pos < 1 || pos > m_length) {
            return ERROR;
        }
        // data存放被删除的值
        data = &m_elem[pos];
        T *p = &m_elem[pos];
        for (T *q = &m_elem[m_length]; p <= q; ++p) {
            *p = *(p + 1);
        }
        --m_length;
        return OK;
    }

    //显示所有元素
    void display(ostream &os = cout, const char seperator = ' ') {
        for (int i = 1; i <= m_length; ++i) {
            os << m_elem[i] << seperator;
        }
    }

    //查找元素，返回位序
    int search(const T key) {
        int i;
        m_elem[0] = key;
        for (i = m_length + 1; m_elem[i] != key; --i)
            ;
        return i;
    }

    //返回第pos个元素的值
    status get_elem(int pos, T &data) {
        if (pos < 1 || pos > m_length) {
            return ERROR;
        }
        data = m_elem[pos];
        return OK;
    }

    //清空顺序线性表
    void clear() { m_length = 0; }

    //元素从begin到end逆置
    status reverse(int begin, int end) {
        //判断参数是否合法
        if (begin < 1 || end > m_length || begin > end) {
            return ERROR;
        }
        for (; begin < end; ++begin, --end) {
            swap(m_elem[begin], m_elem[end]);
        }
        return OK;
    }

    //顺序线性表合并
    status merge(const SqList<T> l) {
        //存储空间不足
        if (this->m_length + l.m_length > this->m_size) {
            return ERROR;
        }
        T *p = &this->m_elem[m_length + 1];
        for (int i = 1; i <= l.m_length; ++i, ++p) {
            *p = l.m_elem[i];
        }
        this->m_length += l.m_length;
        return OK;
    }
};

#endif