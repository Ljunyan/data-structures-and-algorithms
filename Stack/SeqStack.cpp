#include <iostream>

using namespace std;

// 顺序栈 C++容器适配器 stack
class SeqStack
{
private:
    int* mpStack;
    int mtop;
    int mcap;

    void expand(int size)
    {
        int* temp = new int[size];
        memcpy(temp, mpStack, sizeof(int) * mtop);
        delete []mpStack;
        mpStack = temp;
        mcap = size;
    }
public:
    SeqStack(int size = 10)
        : mcap(size)
        , mtop(0)
    {
        mpStack = new int[mcap];
    }
    ~SeqStack()
    {
        delete mpStack;
        mpStack = nullptr;
    }

    // 入栈
    void push(int val)
    {
        if (mtop == mcap) // 扩容
        {
            expand(mcap*2);
        }
        
        mpStack[mtop++] = val;
    }

    // 出栈
    void pop()
    {
        if (mtop == 0)
        {
            throw "stack is empty!"; // 抛异常
        }
        mtop--;
    }

    // 获取栈顶元素
    int top() const
    {
        if (mtop == 0)
        {
            throw "stack is empty!";
        }
        return mpStack[mtop-1];
    }

    // 判断栈空
    bool empty() const
    {
        return mtop==0;
    }

    // 栈元素个函数
    int size()
    {
        return mtop;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4};
    SeqStack s;
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