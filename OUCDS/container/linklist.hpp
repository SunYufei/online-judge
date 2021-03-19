#ifndef LINKLIST_H_
#define LINKLIST_H_

template <typename T>
struct node {
    T data;
    node* prev;
    node* next;

    node(T data, node* prev = nullptr, node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

template <typename T>
class list {
   public:
    list() {}

    ~list() {}

    bool empty() {}

   private:
    node<T>* m_head;
};

#endif