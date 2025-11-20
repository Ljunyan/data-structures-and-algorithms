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
    friend void MergeLink(Clink &link1, Clink &link2);
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

// 合并两个有序的单链表
void MergeLink(Clink &link1, Clink &link2)
{
    
    Node* last = link1.head_;
    Node* p = link1.head_->next_;
    Node* q = link2.head_->next_;
    q->next_ = nullptr;

    while (q != nullptr && p != nullptr)
    {
        if (q->data_ <= p->data_)
        {
            last->next_ = q;
            q = q->next_;
            last = last->next_;
        }
        else if(q->data_ > p->data_)
        {
            last->next_ = p;
            p = p->next_;
            last = last->next_;
        }
    }

    if (p == nullptr)
    {
        last->next_ = q;
    }
    else if(q == nullptr)
    {
        last->next_ = p;
    }
    
}

// 判断单链表是否有环，存在的找到环的入口
bool IsLinkHasCircle(Node* head, int &val)
{
    //  定义快慢指针
    Node* fast = head;
    Node* slow = head;

    while (fast != nullptr && fast->next_ != nullptr)
    {
        slow = slow->next_;
        fast = fast->next_->next_;

        if (slow == fast)
        {
            // 快慢指针再次遇见，链表存在环
            fast = head;
            while (fast != slow)
            {
                slow = slow->next_;
                fast = fast->next_;
            }
            val = slow->data_;
            return true;
        }
        
    }
    return false;
}

// 判断两个单链表是否相交，如果相交，返回相交节点的值
bool IsLinkHasMerge(Node* head1, Node* head2, int &val)
{
    int i=0, j=0;
    Node* p = head1;
    Node* q = head2;
    while (p != nullptr)
    {
        p = p->next_;
        i++;
    }
    while (q != nullptr)
    {
        q = q->next_;
        j++;
    }

    p = head1;
    q = head2;
    if (i >= j)
    {
        for (int k = 0; k < i-j; k++)
        {
            p = p->next_;
        }
    }
    else
    {
        for (int k = 0; k < j-i; k++)
        {
            q = q->next_;
        }
    }

    
    while (p != nullptr && q != nullptr)
    {
        if (p == q)
        {
            val = p->data_;
            return true;
        }
        p = p->next_;
        q = q->next_;
    }
    return false;
}

int main()
{
    Node head1, head2;
    Node a1(5), a2(60), a3(40), a4(8);
    Node b1(50), b2(5);

    head1.next_ = &a1;
    a1.next_ = &a2;
    a2.next_ = &a3;
    a3.next_ = &a4;

    head2.next_ = &b1;
    b1.next_ = &b2;
    b2.next_ = &a2;

    int val;
    if(IsLinkHasMerge(&head1, &head2, val))
    {
        cout << "相交节点的值是" << val << endl;
    }

}

#if 0
int main()
{
    Node head;
    Node n1(25), n2(67), n3(32), n4(18);
    head.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;
    n4.next_ = &n2;

    int val;
    if(IsLinkHasCircle(&head, val))
    {
        cout << "链表存在环，入口节点是：" << val << endl;
    }
    
}


int main()
{
    int arr[] = {25, 37, 52, 78, 88, 92, 98, 108};
    int brr[] = {13, 23, 56, 62, 77, 109};

    Clink link1, link2;

    for (int v : arr)
    {
        link1.InsertTail(v);
    }
    for (int v : brr)
    {
        link2.InsertTail(v);
    }
    
    link1.show();
    link2.show();
    
    MergeLink(link1, link2);
    link1.show();
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