//
//	LinkList.h
//	带头结点单链表
//
//	2015-12-27
//
#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int status;

template <typename T> struct node {
    T data;
    node *next;
};

template <typename T> class LinkList {
  private:
    node<T> *head;

  public:
    LinkList() {
        head = new node<T>;
        head->next = NULL;
    }

    LinkList(const LinkList<T> &from) {
        this->head = new node<T>;
        node<T> *p = this->head;
        node<T> *q = from.head->next;
        node<T> *s;
        while (q != NULL) {
            s = new node<T>;
            s->data = q->data;
            s->next = NULL;
            p->next = s;
            p = s;
            q = q->next;
        }
    }

    ~LinkList() {
        node<T> *q;
        while (head != NULL) {
            q = head->next;
            delete head;
            head = q;
        }
    }

    //插入元素
    status insert(int pos, T e) {
        node<T> *p = head;
        int j = 0;
        //寻找第pos-1个结点
        while (p && j < pos - 1) {
            p = p->next;
            ++j;
        }
        // pos<1或者>表长
        if (NULL == p || j > pos - 1) {
            return ERROR;
        }
        node<T> *s = new node<T>;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return OK;
    }

    //删除结点
    status delete_node(int pos, T *e = NULL) {
        node<T> *p = head;
        int j = 0;
        //寻找第pos个结点，并令p指向它
        while (NULL != p->next && j < pos - 1) {
            p = p->next;
            ++j;
        }
        //删除位置不合理
        if (NULL == p->next || j > pos - 1) {
            return ERROR;
        }
        node<T> *q = p->next;
        p->next = q->next;
        e = &(q->data);
        delete q;
        return OK;
    }

    //将linklist置为空表
    void clear() {
        node<T> *p = head->next;
        node<T> *q;
        while (p != NULL) {
            q = p->next;
            delete p;
            p = q;
        }
        head->next = NULL;
    }

    //判断是否为空表
    bool empty() { return (NULL == head->next); }

    //单链表长度
    int length() {
        int i = 0;
        node<T> *p = head->next;
        while (p != NULL) {
            ++i;
            p = p->next;
        }
        return i;
    }

    //找到元素e所在位序
    int search(const T key) {
        int i = 0;
        node<T> *p = head->next;
        while (p != NULL) {
            ++i;
            if (key == p->data) {
                return i;
            }
            p = p->next;
        }
        return 0;
    }

    //逆置
    status reverse(int begin, int end) {
        //参数越界
        if (begin < 1 || end > this->length()) {
            return ERROR;
        }
        int i;
        // m指向begin前一结点
        node<T> *m = head;
        for (i = 1; i < begin; ++i) {
            m = m->next;
        }
        // p指向begin位序结点
        node<T> *p = m->next;
        // q指向end下一个位序结点
        node<T> *q = p;
        for (i = 1; i <= end - begin + 1; ++i) {
            q = q->next;
        }
        //将链表分成两部分
        m->next = q;
        // p指向的需要逆置的链表插入到原链表begin处
        for (i = 1; i <= end - begin + 1; ++i) {
            m->next = p;
            p = p->next;
            m->next->next = q;
            q = m->next;
        }
        return OK;
    }

    //显示单链表元素
    void display(ostream &os = cout, const char seperator = ' ') {
        node<T> *p = head->next;
        while (p != NULL) {
            cout << p->data << seperator;
            p = p->next;
        }
    }

    //单链表合并
    void merge(const LinkList l) {
        // p指向this最后一个结点
        node<T> *p = this->head;
        while (p->next != NULL) {
            p = p->next;
        }
        // q指向l第一个结点
        node<T> *q = l.head->next;
        //合并
        node<T> *s;
        while (q != NULL) {
            s = new node<T>;
            s->data = q->data;
            s->next = NULL;
            p->next = s;
            p = s;
            q = q->next;
        }
    }
};

#endif