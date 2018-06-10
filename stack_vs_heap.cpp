#include <iostream>

using namespace std;

int main()
{
    int * ptr = new int(2);
    cout<<"address:"<<ptr<<endl;
    cout<<"dereference value:"<<*ptr<<endl;
    delete ptr;
    return 0;
}

指针（pointer）：
int a = 0;
int *ptr = &a;
Animal*ptr 
一个指向int的指针叫pointer，提取a的内存地址赋值给它，存在stack上
在stack 里，out of scope之后，它所占用的内存空间都会被自动回收

heap：
int * ptr = new int(2);
指向int的指针，在heap上分配（new）出的一个内存空间，把2传进去，再把这个地址传给pointer
dereference：
在获取pointer之后，加个*就把它指向地址的值拿到

delete：
释放pointer指向的heap上的那一块内存空间，即new的那块空间被删掉了，但是在stack上的pointer占用的空间依然存在。
memory leak：
如果new完之后忘记删除了，heap上的这块内存空间就永远不能被释放了

