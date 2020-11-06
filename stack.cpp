#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

template <class T>
class Stack
{
private:
    vector<T> elems; // 元素
    int MaxSize;

public:
    Stack(int const &maxSize)
    {
        MaxSize = maxSize;
    }
    void push(T const &); // 入栈
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素
    bool empty() const
    { // 如果为空则返回真。
        return elems.empty();
    }
    bool full() const
    { // 如果为满则返回真。
        return elems.size() == MaxSize;
    }
    int size() const // 返回栈的元素数量
    {
        return elems.size();
    }
};

template <class T>
void Stack<T>::push(T const &elem)
{
    // 追加传入元素的副本
    if (full())
    {
        throw out_of_range("Stack<>::push(): full stack");
    }
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

int main()
{
    try
    {
        Stack<int> intStack(1);       // int 类型的栈,最大长度为1
        Stack<string> stringStack(5); // string 类型的栈

        // 操作 int 类型的栈
        intStack.push(114514);
        cout << intStack.top() << endl
             << intStack.size() << endl;
        //intStack.push(541114);      // 测试栈已满时的错误提示

        // 操作 string 类型的栈
        stringStack.push("24YO, Student");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
}
