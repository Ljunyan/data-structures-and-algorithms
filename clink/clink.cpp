#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// 节点类型
struct Node
{
    Node(int data = 0) : data_(data), next_(nullptr){}
    int data_;
    Node* next_;
};

class Clink
{
private:
    Node* head_;

    friend void ReverseLink(Clink &link);
    friend bool GetLastKNode(Clink &link, int k);
public:
    Clink()
    {
        // 给head_初始化指向头节点
        head_ = new Node();
    }
    ~Clink()
    {
        Node* p = head_;
        // 节点的释放
        while (p != nullptr)
        {
            delete []p;
            head_ = head_->next_;
            p = head_;
        }
    }

    // 链表的尾插法
    void InsertTail(int val)
    {
        // 先找到当前链表的末尾节点
        Node* p = head_;
        while (p->next_ != nullptr)
        {
            p = p->next_;
        }

        //生成新节点
        Node* node = new Node(val);
        // 把新节点挂在尾节点的后面
        p->next_ = node;
    }

    // 链表的头插法
    void InsertHead(int val)
    {
        //生成新节点
        Node* node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
    }

    //链表节点的删除
    void RemoveAll(int val)
    {
        Node* slow = head_;
        Node* fast = head_->next_;

        if (fast == nullptr)
        {
            return;
        }
        // 要用delet释放内存
        while (slow->next_ != nullptr)
        {
            if (fast->data_ == val)
            {
                fast = fast->next_;
                slow->next_ = fast;
                continue;
            }
            slow = fast;
            fast = fast->next_;
        }
        
    }

    // 搜索 O(n)
    bool Find(int val)
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                return 1;
            }
            p = p->next_;
        }
        return 0;
    }

    // 链表打印
    void show()
    {
        Node* p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }
};

// 单链表逆序
void ReverseLink(Clink &link)
{
    Node* p = link.head_->next_;
    if (p == nullptr)
    {
        return;
    }
    
    link.head_->next_ = nullptr;

    Node* q;
    while (p != nullptr)
    {
        q = p;
        p = p->next_;
        q->next_ = link.head_->next_;
        link.head_->next_ = q;
    }
}

// 获取倒数第 k 个节点的值
bool GetLastKNode(Clink &link, int k)
{
    Node* fast = link.head_;
    Node* slow = fast;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next_; 
        if (fast == nullptr)
        {
            return false;
        }
    }
    
    while (fast != nullptr)
    {
        fast = fast->next_;
        slow = slow->next_;
    }
    return true;
}

int main()
{
    Clink link;
    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        int val = rand() % 10;
        cout << val << " ";
        link.InsertTail(val);
    }
    cout << endl; 
    link.show();

    ReverseLink(link);
    link.show();

    if(GetLastKNode(link, 6))
    {
        cout << "true" << endl;
    }
}


#if 0
int main()
{
    Clink link;
    srand(time(0));

    for (int i = 0; i < 20; i++)
    {
        int val = rand() % 10;
        cout << val << " ";
        link.InsertTail(val);
    }
    cout << endl; 
    
    link.show();

    link.RemoveAll(2);
    link.show();
}
#endif