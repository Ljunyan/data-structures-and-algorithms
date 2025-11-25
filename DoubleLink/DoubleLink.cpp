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

class DoubleLink
{
private:
    Node* head_;
public:
    DoubleLink()
    {
        head_ = new Node();
    }
    ~DoubleLink()
    {
        Node* p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

    // Í·²å
    void InsertHead(int val)
    {
        Node* n = new Node(val);
        if (head_->next_ != nullptr)
        {
            head_->next_->pre_ = n;
        }
        n->next_ = head_->next_;
        n->pre_ = head_;
        head_->next_ = n;
    }

    // Î²²å
    void InsertTail(int val)
    {
        Node* n = new Node(val);
        Node* p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }
        p->next_ = n;
        n->pre_ = p;
    }

    // Êä³ö
    void Show()
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }

    // É¾³ý
    void RemoveAll(int val)
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                p->pre_->next_ = p->next_;
                if (p->next_ != nullptr)
                {
                    p->next_->pre_ = p->pre_;
                }
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

    // ½ÚµãËÑË÷
    bool Find(int val)
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                return true;
            }
            else
            {
                p = p->next_;
            }
        }
        return false;
    }
};

int main()
{
    DoubleLink DLink;
    DLink.InsertTail(1);
    DLink.InsertTail(1);
    DLink.InsertTail(3);
    DLink.InsertTail(4);

    DLink.RemoveAll(1);
    DLink.Show();
}