#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr){}
    int data_;
    Node* next_;
};

// 约瑟夫环问题，不带头节点
// 第 k 个开始，每次第 m 出列
Node* Joseph(Node* head, int k, int m)
{
    if (head->next_ == head || k <= 0 || m <= 0) // 1 都是自己
    {
        return nullptr;
    }

    Node* fast = head;
    Node* slow = fast;
    Node* result_head = new Node();
    Node* q = result_head;

    while (slow->next_ != fast)
    {
        slow = slow->next_;
    }
    // cout << fast->data_ << endl;
    // cout << slow->data_ << endl;
    // cout << "111" << endl;
    while (--k > 0)
    {
        fast = fast->next_;
        slow = slow->next_;
    }
    // cout << fast->data_ << endl;
    // cout << slow->data_ << endl;
    // cout << "222" << endl;
    while (fast != fast->next_)
    {
        int count = m;
        while (--count > 0)
        {
            fast = fast->next_;
            slow = slow->next_;
        }
        q->next_ = fast;
        q = q->next_;
        
        // cout << q->data_ << " ";
        slow->next_ = fast->next_;
        fast = fast->next_;
    }
    q->next_ = fast;
    // cout << q->next_->data_ << endl;
    q->next_->next_ = nullptr;
    q = nullptr;
    return result_head->next_;
}

void ShowSingleLink(Node* n)
{
    Node* p = n;
    while (p != nullptr)
    {
        cout << p->data_ << " ";
        p = p->next_;
    }
    cout << endl;
}

int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n1;

    Node* node = Joseph(n1, 1, 2);
    ShowSingleLink(node);

    delete n1;
    delete n2;
    delete n3;
    n1 = nullptr;
    n2 = nullptr;
    n3 = nullptr;
}