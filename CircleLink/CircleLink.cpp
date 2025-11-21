#include <iostream>
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

    // β�巨, o(1)
    void InsertTail(int val)
    {
        Node* n = new Node(val);
        n->next_ = tail_->next_;
        tail_->next_ = n;
        tail_ = n;
    }

    // ͷ�巨
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
};

int main()
{

}