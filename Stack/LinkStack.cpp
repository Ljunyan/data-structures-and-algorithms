#include <iostream>

using namespace std;

// 链式栈
class LinkStack
{
private:
    struct Node
    {
        Node(int data = 0) : data_(data), next_(nullptr){}
        int data_;
        Node* next_;
    };

    Node* head_;
    int size_;
    
public:
    LinkStack() : size_(0)
    {
        head_ = new Node;
    }
    ~LinkStack()
    {
        Node* p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

    // 入栈
    void push(int val)
    {
        Node* node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
        size_++;
    }

    // 出栈
    void pop()
    {
        if (head_->next_ == nullptr)
        {
            throw "stack is empty";
        }
        Node* p = head_->next_;
        head_->next_ = p->next_;
        delete p;
        size_--;
    }

    // 获取栈顶元素
    int top() const
    {
        if (head_->next_ == nullptr)
        {
            throw "stack is empty";
        }
        return head_->next_->data_;
    }

    // 判空
    bool empty() const
    {
        return head_->next_==nullptr;
    }

    // 返回元素个数
    int size()
    {
        return size_;
    }
};


int main()
{
    int arr[] = {1, 2, 3, 4};
    LinkStack s;
    for (int v : arr)
    {
        s.push(v);
    }
    
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}