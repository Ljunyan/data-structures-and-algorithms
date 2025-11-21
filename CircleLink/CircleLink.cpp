#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class CircleLink
{
private:
    struct Node
    {
        Node(int data = 0) : data_(data), next_(nullptr){}
        int data_;
        Node* next_;
    };

    Node* head_;
    Node* tail_;
    
public:
    CircleLink()
    {
        head_ = new Node();
        tail_ = head_;
        head_->next_ = head_;
    }
    ~CircleLink()
    {
        Node* p = head_->next_;
        while (p->next_ != head_)
        {
            head_->next_ = p->next_;
            delete p;
            p = head_->next_;
        }
        delete head_;
    }

    // 尾插法, o(1)
    void InsertTail(int val)
    {
        Node* n = new Node(val);
        n->next_ = tail_->next_;
        tail_->next_ = n;
        tail_ = n;
    }

    // 头插法
    void InsertHead(int val)
    {
        Node* n = new Node(val);
        n->next_ = head_->next_;
        head_->next_ = n;
        if (n->next_ == head_)
        {
            tail_ = n;
        }
    }

    // 删除
    bool Remove(int val)
    {
        Node* p = head_;
        Node* q = head_->next_;

        while (q != head_)
        {
            if (q->data_ == val)
            {
                p->next_ = q->next_;
                delete q;
                if (p->next_ == head_)
                {
                    tail_ = p;
                }
                return true;
            }
            q = q->next_;
            p = p->next_;
        }
        return false;
    }

    // 查询
    bool find(int val)
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                return true;
            }
            p = p->next_;
        }
        return false;
    }

    void show() const
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }
};

int main()
{
    CircleLink C;
    srand(time(0));
    C.InsertHead(1);
    for (int i = 0; i < 10; i++)
    {
        C.InsertTail(rand() % 10);
    }
    C.show();
    if(C.find(1))
    {
        cout << "successful" << endl;
        // C.show();
    }
    else
    {
        cout << "fail" << endl;
    }
}