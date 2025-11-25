#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

struct Node
{
    Node(int data = 0)
        : data_(data)
        , pre_(nullptr)
        , next_(nullptr)
    {}
    int data_;
    Node* pre_;
    Node* next_;
};

class DoubleCircleLink
{
private:
    Node* head_;
public:
    DoubleCircleLink()
    {
        head_ = new Node();
        head_->next_ = head_;
        head_->pre_ = head_;
    }
    ~DoubleCircleLink()
    {
        Node* p = head_->next_;

        while (p != head_)
        {
            head_->next_ = p->next_;
            p->next_->pre_ = head_;
            delete p;
            p = head_->next_;
        }
        delete head_;
        head_ = nullptr;
    }

    // Í·²å
    void InsertHead(int val)
    {
        Node* n = new Node(val);
        n->next_ = head_->next_;
        head_->next_->pre_ = n;
        head_->next_ = n;
        n->pre_ = head_;
    }

    // Î²²å
    void InsertTail(int val)
    {
        Node* n = new Node(val);
        head_->pre_->next_ = n;
        n->pre_ = head_->pre_;
        head_->pre_ = n;
        n->next_ = head_;
    }

    // É¾³ý
    void Remove(int val)
    {
        Node* p = head_->next_;
        while (p != head_)
        {
            if (p->data_ == val)
            {
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                Node* next = p->next_;
                delete p;
                p = next;
            }
            else
            {
                p = p->next_;
            }
        }
    }

    // ËÑË÷
    bool Find(int val)
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

    // ´òÓ¡
    void Show()
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
    DoubleCircleLink DLink;
    DLink.InsertTail(1);
    DLink.InsertTail(1);
    DLink.InsertTail(3);
    DLink.InsertTail(4);

    // DLink.Remove(1);
    DLink.Show();

    if(DLink.Find(1))
    {
        cout << "ÕÒµ½ÁË" << endl;
    }
}