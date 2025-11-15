#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;


// 移除元素，
int RemoveElement(int arr[], int val)
{
    int* p = arr;
    int* q = arr + 10 - 1;

    while (p <= q)
    {
        
        if (*q == val)
        {
            q--;
            continue;
        }

        if (*p != val)
        {
            p++;
            continue;
        }

        int temp = *p;
        *p = *q;
        *q = temp;
        q--;
        p++;
    }
    return (p-arr);
}

int main()
{
    srand(time(0));
    int arr[10] = {0};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        arr[i] = rand()%10;
    }
    
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    int len = RemoveElement(arr, 2);
    cout << "len = ";
    cout << len << endl;

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}




#if 0
// 整形数组，把偶数调整到左边，奇数到右边
void AdjustArray(int arr[], int size)
{
    int* p = arr;              // front pointer
    int* q = arr + size - 1;   // back pointer

    while (p < q)
    {
        // if ((*p & 0x1) == 0) // 偶数
        // {
        //     p++;
        //     continue;
        // }
        while (p < q)
        {
            if ((*p & 0x1) == 1)
            {
                break;
            }
            p++;
        }
        
        
        if ((*q & 0x1) == 1) // 奇数
        {
            q--;
            continue;
        }
        
        int temp = *p;
        *p = *q;
        *q = temp;

        p++;
        q--;
    }
    
}

int main()
{
    int arr[10] = {0};
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
    
    AdjustArray(arr, sizeof(arr)/sizeof(int));
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
}


// 逆序字符串，双指针（一前一后）
void Reverse(char arr[], int size)
{
    char* p = arr;              // front pointer
    char* q = arr + size - 1;   // back pointer

    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}

int main()
{
    char arr[] = "hello world";
    Reverse(arr, strlen(arr));
    cout << arr << endl;
}

class Array
{
public:
    Array(int size = 10): mCur(0), mCap(size)
    {
        mpArr = new int[mCap]();
    }
    ~Array()
    {
        delete []mpArr;
        mpArr = nullptr;
    }

    // 末尾增加元素
    void push_back(int val)
    {
        if (mCur == mCap) // 数组满了，扩容
        {
            expand(2 * mCap);
        }
        mpArr[mCur] = val;
        mCur++;
    }
    // 末尾删除元素
    void pop_back()
    {
        if (mCur == 0)
        {
            return;
        }        
        mCur--;
    }
    // 按位置增加元素
    void insert(int pos, int val)
    {
        if (pos < 0 || pos > mCur)
        {
            return;
        }

        if (mCur == mCap) // 数组满了，扩容
        {
            expand(2 * mCap);
        }
        
        for (int i = mCur-1; i >= pos; i--)
        {
            mpArr[i+1] = mpArr[i];
        }

        mpArr[pos] = val;
        mCur++;
    }
    
    // 按位置删除
    void erase(int pos)
    {
        if (pos < 0 || pos >= mCur)
        {
            return;
        }

        for (int i = pos+1; i < mCur; i++)
        {
            mpArr[i-1] = mpArr[i];
        }
        
        mCur--;
    }
    
    // 元素查询
    int find(int val)
    {
        for (int i = 0; i < mCur; i++)
        {
            if (mpArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    // 打印
    void show()const
    {
        for (int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }


private:
    int* mpArr; // 指向可扩容的数组内存
    int mCap;  // 数组的容量
    int mCur;   // 数组有效元素个数

    // 内部数组扩容接口
    void expand(int size) // 开辟更长内存，拷贝数据，释放原内存
    {
        int* p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete []mpArr;

        mpArr = p;
        mCap = size;
    }
};

int main()
{
    Array arr;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100);
    }
    arr.show();
    arr.pop_back();
    arr.show();

    arr.insert(0, 100);
    arr.show();

    arr.insert(10, 200);
    arr.show();

    int pos = arr.find(100);
    if (pos != -1)
    {
        arr.erase(pos);
        arr.show();
    }
    
}
#endif