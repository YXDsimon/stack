#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

template <class T>
class Queue
{
private:
    vector<T> elems; // 元素
    int MaxSize;

public:
    Queue(int const &maxSize)
    {
        MaxSize = maxSize;
    }
    void push(T const &); // 入队
    void pop();           // 出队
    T top() const;        // 返回队尾元素
    bool empty() const
    { // 如果为空则返回真。
        return elems.empty();
    }
    bool full() const
    { // 如果为满则返回真。
        return elems.size() == MaxSize;
    }
    int size() const // 返回队的元素数量
    {
        return elems.size();
    }
};

template <class T>
void Queue<T>::push(T const &elem)
{
    // 追加传入元素的副本
    if (full())
    {
        throw out_of_range("Queue<>::push(): full Queue");
    }
    elems.insert(elems.begin(), elem);
}

template <class T>
void Queue<T>::pop()
{
    if (empty())
    {
        throw out_of_range("Queue<>::pop(): empty Queue");
    }
    elems.pop_back();
}

template <class T>
T Queue<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Queue<>::top(): empty Queue");
    }
    // 返回最后一个元素的副本
    return elems.back();
}
int main()
{
    try
    {
        Queue<int> intQueue(1);       // int 类型的队,最大长度为1
        Queue<string> stringQueue(5); // string 类型的队

        // 操作 int 类型的队
        intQueue.push(114514);
        cout << intQueue.top() << endl
             << intQueue.size() << endl;
        //intQueue.push(541114);      // 测试队已满时尝试入队

        // 操作 string 类型的队
        stringQueue.push("24YO, Student");
        stringQueue.push("aaaaaaaa");
        cout << stringQueue.top() << std::endl;
        stringQueue.pop();
        cout << stringQueue.top() << std::endl;
    }
    catch (exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
}
